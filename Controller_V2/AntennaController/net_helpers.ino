
unsigned long timestart = 0;
unsigned long timeout = 0;
int trial = 0;
// init and get the time
// configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);

//
//
//


void printLocalTime() {
  struct tm timeinfo;
  if (!getLocalTime(&timeinfo)) {
    Serial.println("Failed to obtain time");
    return;
  }
  Serial.println(&timeinfo, "%d-%m-%Y %H:%M");
  char timeStringBuff[50];  //50 chars should be enough
  strftime(timeStringBuff, sizeof(timeStringBuff), "%d-%m-%Y %H:%M", &timeinfo);
  lv_label_set_text(ui_lblDateTime, timeStringBuff);
}

void enumerateWiFI() {
  Serial.println("starting to scan now");
  // finding the networks available nearby
  int netCount = WiFi.scanNetworks();
  Serial.println("scan completed");
  if (netCount == 0) {
    Serial.println("no network detected");
    wifiList = "------";
  } else {
    Serial.print(netCount);
    Serial.println(" networks found");
    for (int nn = 0; nn < netCount; ++nn) {
      // The number should start from 1 and not 0
      // Print SSID(Service Set Identifier)
      wifiList = wifiList + String(WiFi.SSID(nn)) + "\n";
      Serial.print(WiFi.SSID(nn));
    }
  }
  wifiList.remove(wifiList.length() - 2, 2);
  Serial.println(wifiList);
  lv_roller_set_options(ui_rollerWifiList, wifiList.c_str(), LV_ROLLER_MODE_NORMAL);
}

void enumerateWiFI2() {
  //String a;
  String wifiListDefault = "WifiHome\nAlfa\nBeta\nSiecSasiada\nEircom43872";
  String wifiList;
  const char* wifiListActual;
  Serial.println("starting to scan now");
  // finding the networks available nearby
  int netCount = WiFi.scanNetworks();
  Serial.println("scan completed");
  if (netCount == 0) {
    Serial.println("no network detected");
    wifiList = "------";
  } else {
    Serial.print(netCount);
    Serial.println(" networks found");
    for (int nn = 0; nn < netCount; ++nn) {
      // The number should start from 1 and not 0
      Serial.print(nn + 1);
      Serial.print(" ---- ");
      // Print SSID(Service Set Identifier)
      wifiList = wifiList + String(WiFi.SSID(nn)) + "\n";
      String a = wifiListActual + String(WiFi.SSID(nn)) + "\n";
      wifiListActual = a.c_str();
      //Serial.println(wifiListActual);
      Serial.print(WiFi.SSID(nn));
      Serial.print(" ---- ");
      // Print RSSI(Received Signal Strength Indicator)
      Serial.print(WiFi.RSSI(nn));
      // print the unit
      Serial.print(" dB ---- ");
      String enType = "";
      wifi_auth_mode_t encryp_type = WiFi.encryptionType(nn);
      if (encryp_type == WIFI_AUTH_WPA_WPA2_PSK) {
        enType = "WPA_WPA2_PSK";
      } else if (encryp_type == WIFI_AUTH_WPA2_ENTERPRISE) {
        enType = "WPA2_ENTERPRISE";
      } else if (encryp_type == WIFI_AUTH_OPEN) {
        enType = "Open";
      } else if (encryp_type == WIFI_AUTH_WPA_PSK) {
        enType = "WPA_PSK";
      } else if (encryp_type == WIFI_AUTH_WPA2_PSK) {
        enType = "WPA2_PSK";
      } else if (encryp_type == WIFI_AUTH_WEP) {
        enType = "WEP";
      }
      // display encryption type
      Serial.println(enType);
      delay(50);
    }
  }
  Serial.println(wifiListActual);
  lv_roller_set_options(ui_rollerWifiList, wifiListActual, LV_ROLLER_MODE_NORMAL);
}

void connectWifi(String nameSSID, String password, bool UIMessage) {
  WiFi.mode(WIFI_STA);
  WiFi.begin(nameSSID, password);
  Serial.print("Connecting to Wifi...");
  timeout = millis();
  while ((WiFi.status() != WL_CONNECTED) && (millis() - timeout < 8000)) {
    Serial.print(".");
    delay(1000);
  }
  if (WiFi.status() != WL_CONNECTED && WiFi.status() != WL_NO_SSID_AVAIL) {
    Serial.println("Password is not correct");
    if (UIMessage) {
      lv_label_set_text(ui_msgLabelGeneral, "\n\nPassword is not correct");
      _ui_flag_modify(ui_msgPanelSettingsGeneral, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
    }
  } else if (WiFi.status() != WL_CONNECTED && WiFi.status() == WL_NO_SSID_AVAIL) {
    Serial.println("Wifi network is not avaliable");
    if (UIMessage) {
      lv_label_set_text(ui_msgLabelGeneral, "\n\nWifi network is not avaliable");
      _ui_flag_modify(ui_msgPanelSettingsGeneral, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_TOGGLE);
    }
  } else {
    Serial.println("");
    Serial.println("Connected successfully");
    Serial.print("IP Address : ");
    Serial.println(WiFi.localIP());
    trial = 0;
    if (UIMessage) {
      lv_label_set_text_fmt(ui_msgLabelGeneral, "\nConnected successfully\n IP Addres:\n %s", WiFi.localIP().toString());
      _ui_flag_modify(ui_msgPanelSettingsGeneral, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
      saveCurrentSettings(nameSSID, password);
    }
  }
}

void saveCurrentSettings(String nameSSID, String password) {
  SSID = nameSSID;
  SSIDpass = password;
  //NTP;
  NTPServer = ntpServer;
  saveConfig(config_filename);
}

void setNTP(String ntpName) {
  if (ntpName == "Worldwide") {
    ntpServer = ntpServerWW;
  } else if (ntpName == "Europe") {
    ntpServer = ntpServerEurope;
  } else if (ntpName == "Asia") {
    ntpServer = ntpServerAsia;
  } else if (ntpName == "Oceania") {
    ntpServer = ntpServerOceania;
  } else if (ntpName == "North America") {
    ntpServer = ntpServerNAmerica;
  } else if (ntpName == "South America") {
    ntpServer = ntpServerSAmerica;
  }
}

void setNTPServer(lv_event_t* e) {
  // Your code here
  showTime = lv_obj_has_state(ui_swClockEnabled, LV_STATE_CHECKED);
  if (showTime) {  // if switch is enabled set the NTP
    setNTP(String(ntpServer));
    _ui_flag_modify(ui_lblDateTime, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
    NTP = true;
  } else {
    setNTP(NTPServer);
    NTP = false;
    _ui_flag_modify(ui_lblDateTime, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
  }
  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
  printLocalTime();
  saveCurrentSettings(SSID, SSIDpass);
}

void selectedNTPChanged(lv_event_t* e) {

  lv_dropdown_get_selected_str(ui_ntpDropdown, ntpServer, sizeof(ntpServer));
}

void connectNetwork(lv_event_t *e) {
  // Your code here
  // lv_obj_add_event_cb(ui_txtWifiPassword, ui_event_txtWifiPassword, LV_EVENT_APPLY, NULL);
  Serial.println("SSID: " + String(SSIDSelected));
  Serial.println("Pass: " + String(lv_textarea_get_text(ui_txtWifiPassword)));
  connectWifi(SSIDSelected, lv_textarea_get_text(ui_txtWifiPassword), true);
  //connectWifi(wifiScroll.Value, ui_txtWifiPassword.value);
}