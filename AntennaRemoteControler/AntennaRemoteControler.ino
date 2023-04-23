////////////////////////////////////////////////////////////////////////////////////////
//------------------------------------------------------------------------------------//
//                   ESP32 controller for Antenna Switch by EI9SP                     //
//------------------------------------------------------------------------------------//
//   Author:        Robert    EI9ILB@protom.me                                        //
//   Version:       0.2.0                                                             //
//   Date:          23-04-2023                                                        //
//------------------------------------------------------------------------------------//
//  Controller functions:                                                             //
//    - comunnicating with switch ober RS485                                          //
//    - interface with 2 touch buttons                                                //
//    - OLED display                                                                  //
//    - WEB server as interface for managament                                        //
//    - BT managament                                                                 //
//    - MQTT proxy [TBI]                                                              //
//------------------------------------------------------------------------------------//
// Commands supported by switch:                                                      //
//  ax                  Podaj numer anteny                                            //
//  a0                  wszytkie wylaczone                                            //
//  a1                  Antena 1                                                      //
//  a2                  Antena 2                                                      //
//  a3                  Antena 3                                                      //
//  a4                  Antena 4                                                      //
//  all                 wszytkie wlaczone!                                            //
//  t                   Podaj temperature                                             //
//  rs_term_on          Terminacja wlacz                                              //
//  rs_term_off         Terminacja wylacz                                             //
//  reboot              Restart systemu                                               //
//  load                Aktualizuj oprogramowanie                                     //
//  ?                   Wyswielt liste komend                                         //
//------------------------------------------------------------------------------------//
// Changelog:                                                                         //
//  0.1.1    17-04-2023                                                               //
//    - fixed WEB up and down button                                                  //
//    - added debug function                                                          //
//  0.2.0    23-04-2023                                                               //
//    - Added AP mode for setting SSID and Password to EPROM                          //
//    - added N1MM page template                                                      //
//    - updated sending mechanism to switch                                           //
//    - reorganised code requires new way loading process:                            //
//    https://randomnerdtutorials.com/install-esp32-filesystem-uploader-arduino-ide/  //
//                                                                                    //
//------------------------------------------------------------------------------------//
// Bugs:                                                                              //
//                                                                                    //
//------------------------------------------------------------------------------------//
// TODO:                                                                              //
//     - organize code in modules                                                     //
//     - implement MQTT (subscriber and publisher)                                    //
//     - optimize MVC Views                                                           //
//     - add bitmap splash screen                                                     //
//     - block switch if N1MM is transmitting                                         //
//     - add N1MM UDP support for managing switch directly from logger                //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////

// #define PAWEL
#define DEBUG
#ifdef DEBUG
#define DEBUG_PRINT(x)               \
  Serial.print(millis());            \
  Serial.print(":");                 \
  Serial.print(__PRETTY_FUNCTION__); \
  Serial.print(" in ");              \
  Serial.print(__FILE__);            \
  Serial.print(":");                 \
  Serial.print(__LINE__);            \
  Serial.print(" ");                 \
  Serial.println(x);
#else
#define DEBUG_PRINT(x)
#endif
// Libraries
#include <AsyncTCP.h>          //Web server
#include <ESPAsyncWebServer.h> //Web server

#include <SPI.h>              //OLED
#include <Wire.h>             //OLED
#include <Adafruit_GFX.h>     //OLED
#include <Adafruit_SSD1306.h> //OLED
#include "BluetoothSerial.h"  //BT
#include "WiFi.h"             //Wifi
#include <HardwareSerial.h>   //UART
#include "SPIFFS.h"

// HardwareSerial SerialPort(2); // Initialize hardware UART
#ifdef PAWEL
#define SCREEN_WIDTH 128    // OLED display width, in pixels
#define SCREEN_HEIGHT 64    // OLED display height, in pixels
#define SCREEN_ADDRESS 0x78 ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
#else
#define SCREEN_WIDTH 128    // OLED display width, in pixels
#define SCREEN_HEIGHT 32    // OLED display height, in pixels
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
#endif

#define OLED_RESET -1                                                     // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET); // Initialize OLED

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif
BluetoothSerial SerialBT; // Initialize BT

int ENABLE_pin = 4; // ENABLE - direction for uart transmiting (master/SLAVE)
#define RXD2 16     // HW UART
#define TXD2 17     // HW UART

// Global variables to communicate between functions
String btCommand = "";
String btMessageRecieved = "";
// Variables from controler
String currentAnt;
String currTemp = "0.00";

// touch parameters
#define Threshold 20 // Greater the value, more the sensitivity para touch wakeup
#define UP_pin 12
#define DOWN_pin 14
int sensitivity;
int touchLevel = 60;

// WiFi params
IPAddress localIP;                     // Set Your IP
IPAddress localGateway;                // Set your Gateway IP address
IPAddress localMask(255, 255, 255, 0); // Mask hardcoded - to be changed

// Timer variables
unsigned long currentTime = millis(); //    Current time
unsigned long previousTime = 0;       //    Previous time
const long timeoutTime = 2000;        //    Define timeout time in milliseconds (example: 2000ms = 2s)
const long interval = 10000;          // interval to wait for Wi-Fi connection (milliseconds)

AsyncWebServer server(80); // Initializing WEB Server Object

// Variables to save values from HTML form
String ssid;
String pass;
String ip;
String gateway;
String mask;
String n1mm;
String port;

// Search for parameter in HTTP POST request
const char *PARAM_INPUT_1 = "ssid";
const char *PARAM_INPUT_2 = "pass";
const char *PARAM_INPUT_3 = "ip";
const char *PARAM_INPUT_4 = "gateway";
const char *PARAM_INPUT_5 = "mask";

// File paths to save input values permanently
const char *ssidPath = "/ssid.txt";
const char *passPath = "/pass.txt";
const char *ipPath = "/ip.txt";
const char *gatewayPath = "/gateway.txt";
const char *maskPath = "/mask.txt";
const char *n1mmPath = "/n1mm.txt";
const char *portPath = "/port.txt";

void setup() // Mandatory Arduino setup
{
  Serial.begin(9600);
  Serial2.begin(9600, SERIAL_8N1, RXD2, TXD2);
  SerialBT.begin("EI9SP-ANT");
  initSPIFFS();
  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS))
  {
    DEBUG_PRINT(F("SSD1306 allocation failed"));
    for (;;)
      ; // Don't proceed, loop forever
  }
  display.clearDisplay();
  display.display();
  delay(2000);
  InitScreen(); // Draw startup message

  // Set pins
  pinMode(UP_pin, INPUT);
  pinMode(DOWN_pin, INPUT);
  pinMode(ENABLE_pin, OUTPUT);
  digitalWrite(ENABLE_pin, HIGH);
  currentAnt = "a0";

  // Read configuration from FS
  ssid = readFile(SPIFFS, ssidPath);
  pass = readFile(SPIFFS, passPath);
  ip = readFile(SPIFFS, ipPath);
  gateway = readFile(SPIFFS, gatewayPath);
  mask = readFile(SPIFFS, maskPath);
  n1mm = readFile(SPIFFS, n1mmPath);
  port = readFile(SPIFFS, portPath);
  DEBUG_PRINT(ssid);
  DEBUG_PRINT(pass);
  DEBUG_PRINT(ip);
  DEBUG_PRINT(gateway);
  DEBUG_PRINT(mask);
  DEBUG_PRINT(n1mm);
  DEBUG_PRINT(port);

  // start WWW Standard
  if (initWiFi()) // Check if connection with saved data can be established
  {
    StandardServer(); // Sucess - running normal mode
  }
  else
  {
    SetAccessPointMode(); // Ouch - running AP mode to collect right settings
  }
}

void loop() // Arduino Main Loop
{
  GetDataFromSwitch();   //get temp and current antenna from switch
  
  while (SerialBT.available())   // test if BT is available
  {
    btMessageRecieved = SerialBT.readStringUntil('#');
    btMessageRecieved.toLowerCase(); // take all to lower case
    btCommand = btMessageRecieved;

    DEBUG_PRINT("btMessageRecieved  " + btMessageRecieved);
    DEBUG_PRINT("btCommand          " + btCommand);
    ProcessBT(); // Interpret the BT command
  }

  touchRead(UP_pin); // Read touch key UP
  if (touchRead(UP_pin) < touchLevel)
  {
    DEBUG_PRINT("touchsensor key up detected ");
    DEBUG_PRINT(touchRead(UP_pin));
    delay(1);
    currentAnt = DirtyManualSwitch("UP");
    DEBUG_PRINT(currentAnt);
    delay(500);
    SendToSwitch(currentAnt);
  }

  touchRead(DOWN_pin); // Read touch key DOWN
  if (touchRead(DOWN_pin) < touchLevel)
  {
    DEBUG_PRINT("touchsensor key down detected ");
    DEBUG_PRINT(touchRead(DOWN_pin));
    delay(1);
    currentAnt = DirtyManualSwitch("DOWN");
    DEBUG_PRINT(currentAnt);
    delay(500);
    SendToSwitch(currentAnt);
  }
}
