// File ststem operations
String readFile(fs::FS &fs, String filename) {
  Serial.println("readFile -> Reading file: " + filename);

  File file = fs.open(filename);
  if (!file || file.isDirectory()) {
    Serial.println("readFile -> failed to open file for reading");
    return "";
  }

  String fileText = "";
  while (file.available()) {
    fileText = file.readString();
  }

  file.close();
  return fileText;
}

void writeFile(fs::FS &fs, String filename, String message) {
  Serial.println("writeFile -> Writing file: " + filename);
  File file = fs.open(filename, FILE_WRITE);
  if (!file) {
    Serial.println("writeFile -> failed to open file for writing");
    return;
  }
  if (file.print(message)) {
    Serial.println("writeFile -> file written");
  } else {
    Serial.println("writeFile -> write failed");
  }
  file.close();
}

bool readConfig(String file_name) {
  String file_content = readFile(SPIFFS, file_name);

  int config_file_size = file_content.length();
  Serial.println("Config file size: " + String(config_file_size));
  Serial.println(file_content);

  if (config_file_size > 1024) {
    Serial.println("Config file too large");
    return false;
  }
  StaticJsonDocument<1024> doc;
  auto error = deserializeJson(doc, file_content);
  if (error) {
    Serial.println("Error interpreting config file");
    return false;
  }

  // AntennaSwitch _switches = doc["Switches"];
  const String _SSID = doc["SSID"];
  const String _SSID_pass = doc["pass"];
  const bool _NTP = doc["NTP"];
  const String _ntpServer = doc["NTPServer"];

  // ControlleedSwitches = _switches;
  SSID = _SSID;
  SSIDpass = _SSID_pass;
  NTP = _NTP;
  NTPServer = _ntpServer;
  return true;
}

bool saveConfig(String file_name) {
  StaticJsonDocument<1024> doc;

  // write variables to JSON file
  // doc["Switches"] = AntennaSwitch;
  doc["SSID"] = SSID;
  doc["pass"] = SSIDpass;
  doc["NTP"] = NTP;
  doc["NTPServer"] = NTPServer;

  // write config file
  String tmp = "";
  serializeJson(doc, tmp);
  writeFile(SPIFFS, config_filename, tmp);

  return true;
}
// Switching operations
void ActivateAntenna1(lv_event_t *event) {
  ui_event_Panel11(event);
  ActivateAntenna(1);
}
void ActivateAntenna2(lv_event_t *event) {
  ui_event_Panel12(event);
  ActivateAntenna(2);
}
void ActivateAntenna3(lv_event_t *event) {
  ui_event_Panel13(event);
  ActivateAntenna(3);
}
void ActivateAntenna4(lv_event_t *event) {
  ui_event_Panel14(event);
  ActivateAntenna(4);
}
void ActivateAntenna0(lv_event_t *event) {
  
  ActivateAntenna(0);
}
void ui_event_SettingsButton(lv_event_t * e){
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(&ui_Settings, LV_SCR_LOAD_ANIM_MOVE_LEFT, 500, 0, &ui_Settings_screen_init);
    }
}
void ant1Clicked(lv_event_t *e) {
  // Your code here
  //ActivateAntenna(1);
}
void ant2Clicked(lv_event_t *e) {
  // Your code here
  //ActivateAntenna(2);
}
void ant3Clicked(lv_event_t *e) {
  // Your code here
  //ActivateAntenna(3);
}
void ant4Clicked(lv_event_t *e) {
  // Your code here
  //ActivateAntenna(4);
}
void ant0Clicked(lv_event_t *e) {
  // Your code here
  ui_event_DisableAllSwitch(e);
  //ActivateAntenna(0);
}
void ActivateAntenna(int antennaNumber) {
  Serial.println("Antenna " + String(antennaNumber) + " activated");
}
void wifiScrollChanged(lv_event_t* e) {
  lv_roller_get_selected_str(ui_rollerWifiList, SSIDSelected, sizeof(SSIDSelected));
  Serial.println("SelectedWifi:: "+ String(SSIDSelected));
}
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
#if LV_USE_LOG != 0 /* Serial debugging */
void my_print(const char *buf) {
  // LV_UNUSED(level);
  Serial.printf(buf);
  Serial.flush();
}
#endif

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
