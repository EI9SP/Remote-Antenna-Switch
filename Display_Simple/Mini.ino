#include "WiFi.h"
#include "time.h"


/*******************************************************************************
 * LVGL 
 * Dependent libraries:
 * LVGL: https://github.com/lvgl/lvgl.git

 * Touch libraries:
 * FT6X36: https://github.com/strange-v/FT6X36.git
 * GT911: https://github.com/TAMCTec/gt911-arduino.git
 * XPT2046: https://github.com/PaulStoffregen/XPT2046_Touchscreen.git
 *
 * LVGL Configuration file:
 * Copy your_arduino_path/libraries/lvgl/lv_conf_template.h
 * to your_arduino_path/libraries/lv_conf.h
 * Then find and set:
 * #define LV_COLOR_DEPTH     16
 * #define LV_TICK_CUSTOM     1
 *
 * For SPI display set color swap can be faster, parallel screen don't set!
 * #define LV_COLOR_16_SWAP   1
 *
 * Optional: Show CPU usage and FPS count
 * #define LV_USE_PERF_MONITOR 1
 ******************************************************************************/
#include "ui.h"

#include <Arduino_GFX_Library.h>

#define GFX_BL DF_GFX_BL  // default backlight pin, you may replace DF_GFX_BL to actual backlight pin

/* More dev device declaration: https://github.com/moononournation/Arduino_GFX/wiki/Dev-Device-Declaration */
/* More data bus class: https://github.com/moononournation/Arduino_GFX/wiki/Data-Bus-Class */
/* More display class: https://github.com/moononournation/Arduino_GFX/wiki/Display-Class */

#define GFX_BL 44
Arduino_ESP32RGBPanel *bus = new Arduino_ESP32RGBPanel(
  GFX_NOT_DEFINED /* CS */, GFX_NOT_DEFINED /* SCK */, GFX_NOT_DEFINED /* SDA */,
  40 /* DE */, 41 /* VSYNC */, 39 /* HSYNC */, 42 /* PCLK */,
  45 /* R0 */, 48 /* R1 */, 47 /* R2 */, 21 /* R3 */, 14 /* R4 */,
  5 /* G0 */, 6 /* G1 */, 7 /* G2 */, 15 /* G3 */, 16 /* G4 */, 4 /* G5 */,
  8 /* B0 */, 3 /* B1 */, 46 /* B2 */, 9 /* B3 */, 1 /* B4 */
);

// Uncomment for ST7262 IPS LCD 800x480
Arduino_RPi_DPI_RGBPanel *gfx = new Arduino_RPi_DPI_RGBPanel(
  bus,
  800 /* width */, 0 /* hsync_polarity */, 8 /* hsync_front_porch */, 4 /* hsync_pulse_width */, 8 /* hsync_back_porch */,
  480 /* height */, 0 /* vsync_polarity */, 8 /* vsync_front_porch */, 4 /* vsync_pulse_width */, 8 /* vsync_back_porch */,
  1 /* pclk_active_neg */, 16000000 /* prefer_speed */, true /* auto_flush */);

/*******************************************************************************
 * End of Arduino_GFX setting
 ******************************************************************************/



/*******************************************************************************
 * Please config the touch panel in touch.h
 ******************************************************************************/
#include "touch.h"

/* Change to your screen resolution */
static uint32_t screenWidth;
static uint32_t screenHeight;
static lv_disp_draw_buf_t draw_buf;
static lv_color_t *disp_draw_buf;
static lv_disp_drv_t disp_drv;

/* Display flushing */
void my_disp_flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p) {
  uint32_t w = (area->x2 - area->x1 + 1);
  uint32_t h = (area->y2 - area->y1 + 1);

#if (LV_COLOR_16_SWAP != 0)
  gfx->draw16bitBeRGBBitmap(area->x1, area->y1, (uint16_t *)&color_p->full, w, h);
#else
  gfx->draw16bitRGBBitmap(area->x1, area->y1, (uint16_t *)&color_p->full, w, h);
#endif
  lv_disp_flush_ready(disp);
}

void my_touchpad_read(lv_indev_drv_t *indev_driver, lv_indev_data_t *data) {
  if (touch_has_signal()) {
    if (touch_touched()) {
      data->state = LV_INDEV_STATE_PR;

      /*Set the coordinates*/
      data->point.x = touch_last_x;
      data->point.y = touch_last_y;
    } else if (touch_released()) {
      data->state = LV_INDEV_STATE_REL;
    }
  } else {
    data->state = LV_INDEV_STATE_REL;
  }
}
/*******************************************************************************
* Serial port2 for communication with switch inteface
 ******************************************************************************/
#define MYPORT_TX 19
#define MYPORT_RX 20
HardwareSerial SerialPort2(2);

/*******************************************************************************
* global vars
*******************************************************************************/
String currentAnt;
String switchTemp = "0";
String nameSSID = "YOURSSID";
String password = "YOUR_PASSWD";
bool showTime = false;
static unsigned long last_ms;

void setup() {
  Wire.end();
  Serial.begin(115200);
  delay(50);
  SerialPort2.begin(38400, SERIAL_8N1, MYPORT_TX, MYPORT_RX);

  Serial.println("Antenna switch by EI9SP");
  // initialize WiFi
  Serial.println("Initializing WiFi");
  WiFi.mode(WIFI_STA);
  // disconnect to start again
  WiFi.disconnect();
  delay(100);

#ifdef GFX_PWD
  pinMode(GFX_PWD, OUTPUT);
  digitalWrite(GFX_PWD, HIGH);
#endif
  // Init touch device
  touch_init(gfx->width(), gfx->height());

  while (0)
    touch_touched();
  // Init Display
  gfx->begin();
  gfx->fillScreen(BLACK);
#ifdef GFX_BL
  pinMode(GFX_BL, OUTPUT);
  digitalWrite(GFX_BL, HIGH);
#endif
  lv_init();
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

    Serial.println("Setup done");
  }
}

void loop() {
  lv_timer_handler(); /* let the GUI do its work */
  delay(5);
  /*
  unsigned long currentMillis = millis();
  if (currentMillis - last_ms > 3600) {
    CollectDataFromSwitch();
    if (currentAnt == "0") {
      _ui_state_modify(ui_btnAntena1, LV_STATE_CHECKED, _UI_MODIFY_STATE_REMOVE);
      _ui_state_modify(ui_btnAntena2, LV_STATE_CHECKED, _UI_MODIFY_STATE_REMOVE);
      _ui_state_modify(ui_btnAntena3, LV_STATE_CHECKED, _UI_MODIFY_STATE_REMOVE);
      _ui_state_modify(ui_btnAntena4, LV_STATE_CHECKED, _UI_MODIFY_STATE_REMOVE);
      _ui_state_modify(ui_btnAntena5, LV_STATE_CHECKED, _UI_MODIFY_STATE_ADD);

    } else if (currentAnt == "1") {
      _ui_state_modify(ui_btnAntena1, LV_STATE_CHECKED, _UI_MODIFY_STATE_ADD);
      _ui_state_modify(ui_btnAntena2, LV_STATE_CHECKED, _UI_MODIFY_STATE_REMOVE);
      _ui_state_modify(ui_btnAntena3, LV_STATE_CHECKED, _UI_MODIFY_STATE_REMOVE);
      _ui_state_modify(ui_btnAntena4, LV_STATE_CHECKED, _UI_MODIFY_STATE_REMOVE);
      _ui_state_modify(ui_btnAntena5, LV_STATE_CHECKED, _UI_MODIFY_STATE_REMOVE);

    } else if (currentAnt == "2") {
      _ui_state_modify(ui_btnAntena1, LV_STATE_CHECKED, _UI_MODIFY_STATE_REMOVE);
      _ui_state_modify(ui_btnAntena2, LV_STATE_CHECKED, _UI_MODIFY_STATE_ADD);
      _ui_state_modify(ui_btnAntena3, LV_STATE_CHECKED, _UI_MODIFY_STATE_REMOVE);
      _ui_state_modify(ui_btnAntena4, LV_STATE_CHECKED, _UI_MODIFY_STATE_REMOVE);
      _ui_state_modify(ui_btnAntena5, LV_STATE_CHECKED, _UI_MODIFY_STATE_REMOVE);
    } else if (currentAnt == "3") {
      _ui_state_modify(ui_btnAntena1, LV_STATE_CHECKED, _UI_MODIFY_STATE_REMOVE);
      _ui_state_modify(ui_btnAntena2, LV_STATE_CHECKED, _UI_MODIFY_STATE_REMOVE);
      _ui_state_modify(ui_btnAntena3, LV_STATE_CHECKED, _UI_MODIFY_STATE_ADD);
      _ui_state_modify(ui_btnAntena4, LV_STATE_CHECKED, _UI_MODIFY_STATE_REMOVE);
      _ui_state_modify(ui_btnAntena5, LV_STATE_CHECKED, _UI_MODIFY_STATE_REMOVE);
    } else if (currentAnt == "4") {
      _ui_state_modify(ui_btnAntena1, LV_STATE_CHECKED, _UI_MODIFY_STATE_REMOVE);
      _ui_state_modify(ui_btnAntena2, LV_STATE_CHECKED, _UI_MODIFY_STATE_REMOVE);
      _ui_state_modify(ui_btnAntena3, LV_STATE_CHECKED, _UI_MODIFY_STATE_REMOVE);
      _ui_state_modify(ui_btnAntena4, LV_STATE_CHECKED, _UI_MODIFY_STATE_ADD);
      _ui_state_modify(ui_btnAntena5, LV_STATE_CHECKED, _UI_MODIFY_STATE_REMOVE);
    } else {
      _ui_state_modify(ui_btnAntena1, LV_STATE_CHECKED, _UI_MODIFY_STATE_REMOVE);
      _ui_state_modify(ui_btnAntena2, LV_STATE_CHECKED, _UI_MODIFY_STATE_REMOVE);
      _ui_state_modify(ui_btnAntena3, LV_STATE_CHECKED, _UI_MODIFY_STATE_REMOVE);
      _ui_state_modify(ui_btnAntena4, LV_STATE_CHECKED, _UI_MODIFY_STATE_REMOVE);
      _ui_state_modify(ui_btnAntena5, LV_STATE_CHECKED, _UI_MODIFY_STATE_REMOVE);
    }

    last_ms = currentMillis;
    */
    /*
    if (showtime) {
      configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
      printLocalTime();
    }
  }*/
}
