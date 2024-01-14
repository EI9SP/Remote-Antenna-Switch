// #include "AntennaSwitch.h"
#include "FS.h"
#include <SPIFFS.h>
// #include <ArduinoJson.h>
#include <ArduinoJson.h>
#include <lvgl.h>
#include "time.h"
#include "ui.h"
#include "ui_events.h"
#include <Arduino_GFX_Library.h>
#include "WiFi.h"
#include "touch.h"
#include <HardwareSerial.h>


/*******************************************************************************
 * Global variables
 ******************************************************************************/

#define FORMAT_SPIFFS_IF_FAILED true
#define ntpServerAsia "asia.pool.ntp.org";
#define ntpServerEurope "europe.pool.ntp.org";
#define ntpServerNAmerica "north-america.pool.ntp.org";
#define ntpServerSAmerica "south-america.pool.ntp.org";
#define ntpServerOceania "oceania.pool.ntp.org";
#define ntpServerWW "pool.ntp.org";
#define GFX_BL DF_GFX_BL  // default backlight pin, you may replace DF_GFX_BL to actual backlight pin
#define GFX_BL 44
#define LV_USE_LOG 0
//#define MYPORT_TX 17
//#define MYPORT_RX 18


// define filename to store config file
const String config_filename = "/config.json";
char *ntpServer = ntpServerWW;
const long gmtOffset_sec = 0;
const int daylightOffset_sec = 3600;
char clockLabel[] = "";
int switchTemp = 0;

String wifiList;
String switchesList = "---------";
// AntennaSwitch **ControlleedSwitches;
String SSID;
char SSIDSelected[32];
char SSIDSelectedPasswd[40];
String SSIDpass;
bool NTP;
String NTPServer = ntpServerWW;
bool showTime;

static uint32_t screenWidth;
static uint32_t screenHeight;
static lv_disp_draw_buf_t draw_buf;
static lv_color_t *disp_draw_buf;
static lv_disp_drv_t disp_drv;
static unsigned long last_ms;


/*******************************************************************************
 * End of Global variables
 *******************************************************************************/

Arduino_ESP32RGBPanel *bus = new Arduino_ESP32RGBPanel(
  GFX_NOT_DEFINED /* CS */, GFX_NOT_DEFINED /* SCK */, GFX_NOT_DEFINED /* SDA */,
  40 /* DE */, 41 /* VSYNC */, 39 /* HSYNC */, 42 /* PCLK */,
  45 /* R0 */, 48 /* R1 */, 47 /* R2 */, 21 /* R3 */, 14 /* R4 */,
  5 /* G0 */, 6 /* G1 */, 7 /* G2 */, 15 /* G3 */, 16 /* G4 */, 4 /* G5 */,
  8 /* B0 */, 3 /* B1 */, 46 /* B2 */, 9 /* B3 */, 1 /* B4 */
);
Arduino_RPi_DPI_RGBPanel *gfx = new Arduino_RPi_DPI_RGBPanel(
  bus,
  800 /* width */, 0 /* hsync_polarity */, 8 /* hsync_front_porch */, 4 /* hsync_pulse_width */, 8 /* hsync_back_porch */,
  480 /* height */, 0 /* vsync_polarity */, 8 /* vsync_front_porch */, 4 /* vsync_pulse_width */, 8 /* vsync_back_porch */,
  1 /* pclk_active_neg */, 16000000 /* prefer_speed */, true /* auto_flush */);

/* Display flushing */

HardwareSerial SerialPort2 (2); 

void WiFiLoadScreen(lv_event_t *e) {
  // Your code here
  //enumerateWiFI();
}
void ui_event_rollerWifiList(lv_event_t *e) {
  lv_event_code_t event_code = lv_event_get_code(e);
  lv_obj_t *target = lv_event_get_target(e);
  if (event_code == LV_EVENT_VALUE_CHANGED) {
    wifiScrollChanged(e);
  }
}
void ui_event_txtWifiPassword(lv_event_t *e) {
  lv_event_code_t event_code = lv_event_get_code(e);
  lv_obj_t *target = lv_event_get_target(e);
  if (event_code == LV_EVENT_FOCUSED) {
    _ui_flag_modify(ui_Keyboard2, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
  }
  if (event_code == LV_EVENT_DEFOCUSED) {
    _ui_flag_modify(ui_Keyboard2, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
  }
}
void ui_event_connectButton(lv_event_t *e) {
  lv_event_code_t event_code = lv_event_get_code(e);
  lv_obj_t *target = lv_event_get_target(e);
  //Serial.println("Connect button event trigered" + String(event_code) );
  //if (lv_btn_get_state(e) == LV_BTN_STATE_PRESSED) {
  Serial.println("Connect button clicked");
  connectNetwork(e);
  _ui_flag_modify(ui_msgPanelSettingsGeneral, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_TOGGLE);
  //}
}






void setup() {
  Serial.begin(115200);
  SerialPort2.begin(115200, SERIAL_8N1, 18, 17);
  
  // Serial.setDebugOutput(true);
  // while(!Serial);
  Serial.println("Antenna switch by EI9SP");
  // initialize WiFi
  Serial.println("Initializing WiFi");
  WiFi.mode(WIFI_STA);
  // disconnect to start again
  WiFi.disconnect();
  delay(100);

  // Mount SPIFFS and read in config file
  if (!SPIFFS.begin(FORMAT_SPIFFS_IF_FAILED)) {
    Serial.println("setup -> SPIFFS Mount Failed");
  } else {
    Serial.println("setup -> SPIFFS mounted successfully");
    if (readConfig(config_filename) == false) {
      Serial.println("setup -> Could not read Config file -> initializing new file");
      // if not possible -> save new config file
      if (saveConfig(config_filename)) {
        Serial.println("setup -> Config file saved");
      }
    } else {
      connectWifi(SSID,SSIDpass,false);
    }
  }
#ifdef GFX_EXTRA_PRE_INIT
  GFX_EXTRA_PRE_INIT();
#endif

#ifdef GFX_PWD
  pinMode(GFX_PWD, OUTPUT);
  digitalWrite(GFX_PWD, HIGH);
#endif
  Serial.println("setup -> DisplayINIT");
  // Init Display
  gfx->begin();
  gfx->fillScreen(BLACK);
  Serial.println("setup -> GFX Screen set to Black");
#ifdef GFX_BL
  pinMode(GFX_BL, OUTPUT);
  digitalWrite(GFX_BL, HIGH);
#endif
  // Init touch device
  // touch_init(gfx->width(), gfx->height(), gfx->getRotation());
  touch_init(gfx->width(), gfx->height());
  lv_init();

#if LV_USE_LOG != 0
  lv_log_register_print_cb(my_print); /* register print function for debugging */
#endif
  screenWidth = gfx->width();
  screenHeight = gfx->height();
#ifdef ESP32
  disp_draw_buf = (lv_color_t *)heap_caps_malloc(sizeof(lv_color_t) * screenWidth * 10, MALLOC_CAP_INTERNAL | MALLOC_CAP_8BIT);
#else
  disp_draw_buf = (lv_color_t *)malloc(sizeof(lv_color_t) * screenWidth * 10);
#endif
  if (!disp_draw_buf) {
    Serial.println("LVGL disp_draw_buf allocate failed!");
  } else {
    lv_disp_draw_buf_init(&draw_buf, disp_draw_buf, NULL, screenWidth * 10);

    /* Initialize the display */
    lv_disp_drv_init(&disp_drv);
    /* Change the following line to your display resolution */
    disp_drv.hor_res = screenWidth;
    disp_drv.ver_res = screenHeight;
    disp_drv.flush_cb = my_disp_flush;
    disp_drv.draw_buf = &draw_buf;
    lv_disp_drv_register(&disp_drv);

    /* Initialize the (dummy) input device driver */
    static lv_indev_drv_t indev_drv;
    lv_indev_drv_init(&indev_drv);
    indev_drv.type = LV_INDEV_TYPE_POINTER;
    indev_drv.read_cb = my_touchpad_read;
    lv_indev_drv_register(&indev_drv);

    ui_init();
    // MainScreen events
    Serial.println("setup -> Initializing GUI events");



    lv_obj_add_event_cb(ui_Panel11, ActivateAntenna1, LV_EVENT_PRESSED, NULL);
    lv_obj_add_event_cb(ui_Panel12, ActivateAntenna2, LV_EVENT_PRESSED, NULL);
    lv_obj_add_event_cb(ui_Panel13, ActivateAntenna3, LV_EVENT_PRESSED, NULL);
    lv_obj_add_event_cb(ui_Panel14, ActivateAntenna4, LV_EVENT_PRESSED, NULL);

    lv_obj_add_event_cb(ui_LockSwitch, ui_event_LockSwitch, LV_EVENT_VALUE_CHANGED, NULL);
    //lv_obj_add_event_cb(ui_DisableAllSwitch, ui_event_DisableAllSwitch, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_DisableAllSwitch, ActivateAntenna0, LV_EVENT_VALUE_CHANGED, NULL);
    lv_obj_add_event_cb(ui_rollerActiveSwitchHOME, ui_event_rollerActiveSwitchHOME, LV_EVENT_VALUE_CHANGED, NULL);

    lv_obj_add_event_cb(ui_SettingsButton, ui_event_SettingsButton, LV_EVENT_PRESSED, NULL);

    // SettingsScreen events
    lv_obj_add_event_cb(ui_connectButton, ui_event_connectButton, LV_EVENT_PRESSED, NULL);
    lv_obj_add_event_cb(ui_txtWifiPassword, ui_event_txtWifiPassword, LV_EVENT_ALL, NULL);

    Serial.println("setup -> Initializing GUI events ->completed");
    enumerateWiFI();
    Serial.println("Setup done");
  }
  last_ms = millis();
}

void loop() {
  lv_timer_handler(); /* let the GUI do its work */
  delay(5);
  unsigned long currentMillis = millis();
  if (showTime && (currentMillis - last_ms > 3600)) {
    last_ms = currentMillis;
    configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
    printLocalTime();
  }
  /*
  Serial.println(currentMillis - last_ms);
  Serial.println(last_ms);
  Serial.println(currentMillis);
  */
}
