////////////////////////////////////////////////////////////////////////////////////////
//------------------------------------------------------------------------------------//
//                   ESP32 controller for Antenna Switch by EI9SP                     //
//------------------------------------------------------------------------------------//
//   Author:        Robert    EI9ILB@protom.me                                        //
//   Version:       0.1.1 POC                                                         //
//   Date:          17-04-2023                                                        //
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
//  a?                  Podaj numer anteny                                            //
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
// Bugs:                                                                              //
//    - fixed WEB up and down button                                                  //
//    - added debug function                                                          //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////

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

// HardwareSerial SerialPort(2); // Initialize hardware UART

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

#define OLED_RESET -1                                                     // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C                                               ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET); // Initialize OLED

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif
BluetoothSerial SerialBT; // Initialize BT

int ENABLE_pin = 4; // ENABLE - direction for uart transmiting (master/SLAVE)
// #define RXD2 25     // HW UART
// #define TXD2 27     // HW UART
#define RXD2 16
#define TXD2 17

// Global variables to communicate between functions
String btCommand = "";
String btMessageRecieved = "";
String btCommandValue = "";

// touch parameters
#define Threshold 20 // Greater the value, more the sensitivity para touch wakeup
#define UP_pin 12
#define DOWN_pin 14
int sensitivity;
int touchLevel = 40;
// Variables from controler
String currentAnt;
String currTemp = "0.00";
// WiFi params
const char *ssid = "ALFA";                 // Put your WiFI SSID here
const char *password = "1234567;"; // and your password here

// Current time
unsigned long currentTime = millis();
// Previous time
unsigned long previousTime = 0;
// Define timeout time in milliseconds (example: 2000ms = 2s)
const long timeoutTime = 2000;

// Website index page template
const char index_html[] PROGMEM = R"rawliteral(<!DOCTYPE HTML>
<html>
<head>
    <title>Antenna Switch Controller by Sierra Papa DX Group</title>
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link rel="stylesheet" href="https://use.fontawesome.com/releases/v5.7.2/css/all.css" integrity="sha384-fnmOCqbTlWIlj8LyTjo7mOUStjsKC4pOpQbqyi7RrhN7udi9RwhKkMHpvLbHG9Sr" crossorigin="anonymous">
    <style>
        body {
            font-family: Arial;
            text-align: center;
            margin: 0px auto;
            padding-top: 30px;
        }
        html {
     font-family: Arial;
     display: inline-block;
     margin: 0px auto;
     text-align: center;
    }
    h2 { font-size: 3.0rem; }
    p { font-size: 3.0rem; }
    .units { font-size: 1.2rem; }
    .dht-labels{
      font-size: 1.5rem;
      vertical-align:middle;
      padding-bottom: 15px;
    }
        .button {
            padding: 10px 20px;
            font-size: 24px;
            text-align: center;
            outline: none;
            color: #fff;
            background-color: #2f4468;
            border: none;
            border-radius: 5px;
            box-shadow: 0 6px #999;
            cursor: pointer;
            -webkit-touch-callout: none;
            -webkit-user-select: none;
            -khtml-user-select: none;
            -moz-user-select: none;
            -ms-user-select: none;
            user-select: none;
            -webkit-tap-highlight-color: rgba(0, 0, 0, 0);
        }
        .button:hover {
            background-color: #1f2e45
        }
        .button:active {
            background-color: #1f2e45;
            box-shadow: 0 4px #666;
            transform: translateY(2px);
        }
        label {
        display: inline-block;
            margin-top: 1em;
            height: 64px;
        }
        *:disabled {
            background-color: dimgrey;
            color: linen;
            opacity: 1;
        }
        input[type="text"] {
            font-size: 64px;
        }
    </style>
</head>
<body>
    <h1>ESP Switch Controller by EI9SP</h1>
    <button class="button" onmousedown="toggleCheckbox('up');" ontouchstart="toggleCheckbox('up');" onmouseup="toggleCheckbox('UP');" ontouchend="toggleCheckbox('UP');">&nbsp;UP&nbsp;</button>
    <br><br>
      <p>
    <i class="fas fa-wifi" style="color:#00add6;"></i>
    <span class="dht-labels">Antenna</span>
    <span id="antenna">%ANTENNA%</span>
  </p><p>
    <i class="fas fa-thermometer-half" style="color:#059e8a;"></i> 
    <span class="dht-labels">Temperature</span> 
    <span id="temperature">%TEMPERATURE%</span>
    <sup class="units">&deg;C</sup>
  </p><br><br>
    <button class="button" onmousedown="toggleCheckbox('down');" ontouchstart="toggleCheckbox('down');" onmouseup="toggleCheckbox('DOWN');" ontouchend="toggleCheckbox('DOWN');">DOWN</button>
    <script>
        function toggleCheckbox(x) {
            var xhr = new XMLHttpRequest();
            xhr.open("GET", "/" + x, true);
            xhr.send();
        }
        setInterval(function ( ) {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("temperature").innerHTML = this.responseText;
    }
  };
  xhttp.open("GET", "/temperature", true);
  xhttp.send();
}, 100 ) ;

setInterval(function ( ) {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("antenna").innerHTML = this.responseText;
    }
  };
  xhttp.open("GET", "/antenna", true);
  xhttp.send();
}, 100 ) ;
</script>
</body>
</html>
)rawliteral";
String ReturnAntenaToWWW() // Convert current antens too Integer for showing on WWW
{
  int webAnt;
  if (currentAnt == "a1")
  {
    webAnt = 1;
  }
  else if (currentAnt == "a2")
  {
    webAnt = 2;
  }
  else if (currentAnt == "a3")
  {
    webAnt = 3;
  }
  else if (currentAnt == "a4")
  {
    webAnt = 4;
  }
  else if (currentAnt == "a0")
  {
    webAnt = 0;
  }
  return String(webAnt);
}

String GetTemperature() // Get temperature from controller - dummy value st the moment  [TBI]
{
  return currTemp;
}

String processor(const String &var) // Processor function forAsync WEB Server
{

  DEBUG_PRINT(var);

  if (var == "TEMPERATURE")
  {
    return GetTemperature();
  }
  else if (var == "ANTENNA")
  {
    return ReturnAntenaToWWW();
  }
  return String();
}

void notFound(AsyncWebServerRequest *request) // WEB server response function for invalid request
{
  request->send(404, "text/plain", "Not found");
}

AsyncWebServer server(80); // Initializing WEB Server

void PrintCMDOnDisp(String message) // Print custome message on OLED
{
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 15);
  display.println(message);
  display.display();
}

void PrintMSG(String command) // Send command to controller and debuging info to console & OLED - partially dummy [TBI]
{

  DEBUG_PRINT("Command: " + command);
  Serial2.println(command);
  command = "";
}

void UpdateAntenaOnDisp(int output) // Print actual selected antenna on OLED
{
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(1, 1);
  display.println(F("Active antena:"));
  display.setTextSize(2);
  display.setCursor(40, 15);
  display.println(String(output));
  display.display();
}

void ProcessBT() // Process BT commands
{
  if (btCommand == "a0")
  {
    PrintMSG(btCommand);
    UpdateAntenaOnDisp(0);
    currentAnt = "a0";
  }
  if (btCommand == "a1")
  {
    PrintMSG(btCommand);
    UpdateAntenaOnDisp(1);
    currentAnt = "a1";
  }
  if (btCommand == "a2")
  {
    PrintMSG(btCommand);
    UpdateAntenaOnDisp(2);
    currentAnt = "a2";
  }
  if (btCommand == "a3")
  {
    PrintMSG(btCommand);
    UpdateAntenaOnDisp(3);
    currentAnt = "a3";
  }
  if (btCommand == "a4")
  {
    PrintMSG(btCommand);
    UpdateAntenaOnDisp(4);
    currentAnt = "a4";
  }
  if (btCommand == "rs_term_on")
  {
    PrintMSG(btCommand);
    PrintCMDOnDisp("Enable termination");
  }
  if (btCommand == "rs_term_off")
  {
    PrintMSG(btCommand);
    PrintCMDOnDisp("Disable termination");
  }
  if (btCommand == "reboot")
  {
    PrintMSG(btCommand);
    PrintCMDOnDisp("Rebooting remote unit");
  }
  if (btCommand == "load")
  {
    PrintMSG(btCommand);
    PrintCMDOnDisp("Connect unit for F/W update");
  }
}

void ConfirmAntenaOnDisp(int output) // Confirm antenna on controller is same on switch
{
  display.clearDisplay();
  display.setTextSize(1);              // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE); // Draw white text
  display.setCursor(1, 1);             // Start at top-left corner
  display.println(F("Active antena:"));
  display.setTextSize(2);
  display.setCursor(40, 15);
  display.setTextColor(SSD1306_BLACK, SSD1306_WHITE); // reverse collors will indicate bith devices are in sync
  display.println(String(output));
  display.setTextColor(SSD1306_WHITE);
  display.display();
}

String DirtyManualSwitch(String dir) // Process touch buttons
{
  if ((currentAnt == "a0") and (dir == "UP"))
  {
    currentAnt = "a1";
    UpdateAntenaOnDisp(1);
  }
  else if ((currentAnt == "a1") and (dir == "UP"))
  {
    currentAnt = "a2";
    UpdateAntenaOnDisp(2);
  }
  else if ((currentAnt == "a2") and (dir == "UP"))
  {
    currentAnt = "a3";
    UpdateAntenaOnDisp(3);
  }
  else if ((currentAnt == "a3") and (dir == "UP"))
  {
    currentAnt = "a4";
    UpdateAntenaOnDisp(4);
  }
  else if ((currentAnt == "a4") and (dir == "UP"))
  {
    currentAnt = "a0";
    UpdateAntenaOnDisp(0);
  }
  else if ((currentAnt == "a0") and (dir == "DOWN"))
  {
    currentAnt = "a4";
    UpdateAntenaOnDisp(4);
  }
  else if ((currentAnt == "a4") and (dir == "DOWN"))
  {
    currentAnt = "a3";
    UpdateAntenaOnDisp(3);
  }
  else if ((currentAnt == "a3") and (dir == "DOWN"))
  {
    currentAnt = "a2";
    UpdateAntenaOnDisp(2);
  }
  else if ((currentAnt == "a2") and (dir == "DOWN"))
  {
    currentAnt = "a1";
    UpdateAntenaOnDisp(1);
  }
  else if ((currentAnt == "a1") and (dir == "DOWN"))
  {
    currentAnt = "a0";
    UpdateAntenaOnDisp(0);
  }
  return currentAnt;
}

String GetDataFromSwitch() // Get setting from switch
{
  String data_recievied;
  Serial2.println("a?");
  data_recievied = Serial2.readStringUntil('\n');
  if ((data_recievied == "a1") or (data_recievied == "a2") or (data_recievied == "a3") or (data_recievied == "a4") or (data_recievied == "a0"))
  {
    currentAnt = data_recievied;
    data_recievied = "";
  }

  Serial2.println("t");
  data_recievied = Serial2.readStringUntil('\n');
  if ((data_recievied.length() > 1) and (data_recievied.length() < 5))
  {
    currTemp = data_recievied;
  }
}

void SendToSwitch(String command) // Send Command to switch (partial - response implementation pending) [TBI]
{
  Serial2.println(command);
}

void ShowIP() // Show IP on OLED once connected to WiFi
{
  display.clearDisplay();
  display.setTextSize(1);              // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE); // Draw white text
  display.setCursor(5, 5);             // Start at top-left corner
  display.println(F("WIFI IP:"));

  display.setCursor(0, 25); // Start at top-left corner
  display.println(WiFi.localIP());
  display.display();
  delay(5000);
}

void InitScreen() // Init screen - just as example, more advanced need more time ;)
{
  display.clearDisplay();
  display.setTextSize(1);              // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE); // Draw white text
  display.setCursor(5, 5);             // Start at top-left corner
  display.println(F("No to jadyma, "));
  display.println(F("          Chlopy!"));
  display.display();
  delay(2000);
}

void setup() // Mandatory Arduino setup
{
  Serial.begin(9600);
  Serial2.begin(9600, SERIAL_8N1, RXD2, TXD2);
  SerialBT.begin("ESP32_ANT");

  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS))
  {
    DEBUG_PRINT(F("SSD1306 allocation failed"));
    for (;;)
      ; // Don't proceed, loop forever
  }

  // Show initial display buffer contents on the screen --
  // the library initializes this with an Adafruit splash screen.
  // display.display();
  // delay(2000); // Pause for 2 seconds
  // Clear the buffer
  display.clearDisplay();
  // Draw a single pixel in white
  display.drawPixel(10, 10, SSD1306_WHITE);

  // Show the display buffer on the screen. You MUST call display() after
  // drawing commands to make them visible on screen!
  display.display();
  delay(2000);
  InitScreen(); // Draw startup message

  // Set pins
  pinMode(UP_pin, INPUT);
  pinMode(DOWN_pin, INPUT);
  pinMode(ENABLE_pin, OUTPUT);
  digitalWrite(ENABLE_pin, HIGH);
  currentAnt = "a0";

  WiFi.mode(WIFI_STA); // Optional
  DEBUG_PRINT("\nConnecting");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    DEBUG_PRINT('.');
    delay(1000);
  }
  DEBUG_PRINT("\nConnected to the WiFi network");
  Serial.print("Local ESP32 IP: ");
  Serial.println(WiFi.localIP());

  ShowIP();

  Serial2.println("Starting initialisation...");

  // Send web page to client
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send_P(200, "text/html", index_html, processor); });

  // Receive an HTTP GET request
  server.on("/up", HTTP_GET, [](AsyncWebServerRequest *request)
            {
    DirtyManualSwitch("UP");
    SendToSwitch(currentAnt);
    request->send(200, "text/plain", "ok"); });

  // Receive an HTTP GET request
  server.on("/down", HTTP_GET, [](AsyncWebServerRequest *request)
            {
    DirtyManualSwitch("DOWN");
    SendToSwitch(currentAnt);
    request->send(200, "text/plain", "ok"); });

  server.on("/temperature", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send_P(200, "text/plain", GetTemperature().c_str()); });
  server.on("/antenna", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send_P(200, "text/plain", ReturnAntenaToWWW().c_str()); });
  server.onNotFound(notFound);
  server.begin();
}

void loop() // Mandatory Arduino Main Loop
{
  //  Serial.println("LOOP");
  //  Serial2.print("TEST\n");
  // test if BT is available
  while (SerialBT.available())
  {
    btMessageRecieved = SerialBT.readStringUntil('#');
    btMessageRecieved.toLowerCase(); // take all to lower case
    btCommand = btMessageRecieved;

    DEBUG_PRINT("btMessageRecieved  " + btMessageRecieved);
    DEBUG_PRINT("btCommand          " + btCommand);
    ProcessBT(); // Interpret the BT command
  }
  touchRead(UP_pin); // para evitar falsas lecturas
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
  touchRead(DOWN_pin); // para evitar falsas lecturas
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
