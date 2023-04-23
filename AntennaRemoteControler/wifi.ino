
bool initWiFi()
{
  if (ssid == "" || ip == "")
  {
    Serial.println("Undefined SSID or IP address.");
    return false;
  }

  WiFi.mode(WIFI_STA);
  localIP.fromString(ip.c_str());
  localGateway.fromString(gateway.c_str());
  localMask.fromString(mask.c_str());

  if (!WiFi.config(localIP, localGateway, localMask))
  {
    DEBUG_PRINT("STA Failed to configure");
    return false;
  }
  WiFi.begin(ssid.c_str(), pass.c_str());
  DEBUG_PRINT("Connecting to WiFi...");

  unsigned long currentTime = millis();
  previousTime = currentTime;

  while (WiFi.status() != WL_CONNECTED)
  {
    currentTime = millis();
    if (currentTime - previousTime >= interval)
    {
      DEBUG_PRINT("Failed to connect.");
      return false;
    }
  }

  DEBUG_PRINT(WiFi.localIP());
  return true;
}

void SetAccessPointMode()
{
  // Connect to Wi-Fi network with SSID and password
  Serial.println("Setting AP (Access Point)");
  // NULL sets an open Access Point
  WiFi.softAP("EI9SP-SETUP", NULL);

  IPAddress IP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(IP);

  ShowIPAP();
  // Web Server Root URL
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/wifimanager.html", "text/html"); });

  server.serveStatic("/", SPIFFS, "/");

  server.on("/", HTTP_POST, [](AsyncWebServerRequest *request)
            {
              DEBUG_PRINT("Inside AP root)");
      int params = request->params();
      for(int i=0;i<params;i++){
        AsyncWebParameter* p = request->getParam(i);
        
        if(p->isPost()){
          // HTTP POST ssid value
          if (p->name() == PARAM_INPUT_1) {
            ssid = p->value().c_str();
            Serial.print("SSID set to: ");
            Serial.println(ssid);
            // Write file to save value
            writeFile(SPIFFS, ssidPath, ssid.c_str());
          }
          // HTTP POST pass value
          if (p->name() == PARAM_INPUT_2) {
            pass = p->value().c_str();
            Serial.print("Password set to: ");
            Serial.println(pass);
            // Write file to save value
            writeFile(SPIFFS, passPath, pass.c_str());
          }
          // HTTP POST ip value
          if (p->name() == PARAM_INPUT_3) {
            ip = p->value().c_str();
            Serial.print("IP Address set to: ");
            Serial.println(ip);
            // Write file to save value
            writeFile(SPIFFS, ipPath, ip.c_str());
          }
          // HTTP POST gateway value
          if (p->name() == PARAM_INPUT_4) {
            gateway = p->value().c_str();
            Serial.print("Gateway set to: ");
            Serial.println(gateway);
            // Write file to save value
            writeFile(SPIFFS, gatewayPath, gateway.c_str());
          }
          // HTTP POST gateway value
          if (p->name() == PARAM_INPUT_5) {
            mask = p->value().c_str();
            Serial.print("Maks set to: ");
            Serial.println(mask);
            // Write file to save value
            writeFile(SPIFFS, maskPath, mask.c_str());
          }

          //Serial.printf("POST[%s]: %s\n", p->name().c_str(), p->value().c_str());
        }
      }
      request->send(200, "text/plain", "Done. ESP will restart, connect to your router and go to IP address: " + ip);
      delay(3000);
      ESP.restart(); });
      DEBUG_PRINT("Server starting in AP mode");
  server.begin();
}

void StandardServer()
{
  DEBUG_PRINT("\nConnected to the WiFi network");
  Serial.print("Local ESP32 IP: ");
  Serial.println(WiFi.localIP());

  ShowIP();

  // Route for root / web page
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/index.html", "text/html", false, processor); });
  server.serveStatic("/", SPIFFS, "/");

  // Receive an HTTP GET request :UP
  server.on("/up", HTTP_GET, [](AsyncWebServerRequest *request)
            {
    DirtyManualSwitch("UP");
    SendToSwitch(currentAnt);
    request->send(SPIFFS, "/index.html", "text/html", false, processor); });

  // Receive an HTTP GET request: DOWN
  server.on("/down", HTTP_GET, [](AsyncWebServerRequest *request)
            {
    DirtyManualSwitch("DOWN");
    SendToSwitch(currentAnt);
    request->send(SPIFFS, "/index.html", "text/html", false, processor); });
  server.begin();

  server.on("/temperature", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(200, "text/plain", GetTemperature().c_str()); });

  server.on("/antenna", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(200, "text/plain", ReturnAntenaToWWW().c_str()); });

}

String processor(const String &var) // Processor function forAsync WEB Server
{
  DEBUG_PRINT(var);
  if (var == "TEMPERATURE")
  {
    return currTemp;
  }
  else if (var == "ANTENNA")
  {
    return ReturnAntenaToWWW();
  }
  //else if (var == "NETWORKS")
 // {
 //   return GetWifiNetworks();
 // }
  return String();
}

void notFound(AsyncWebServerRequest *request) // WEB server response function for invalid request
{
  request->send(404, "text/plain", "Not found");
}
