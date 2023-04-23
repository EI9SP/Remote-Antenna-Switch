
void PrintCMDOnDisp(String message) // Print custome message on OLED
{
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 15);
  display.println(message);
  display.display();
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

void ShowIPAP() // Show IP on OLED once connected to WiFi
{
  display.clearDisplay();
  display.setTextSize(1);              // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE); // Draw white text
  display.setCursor(5, 1);             // Start at top-left corner
  display.println(F("Caution AP mode!!!"));
  display.setCursor(1, 15);
  display.println(F("WIFI IP:"));

  display.setCursor(0, 25); // Start at top-left corner
  display.println(WiFi.softAPIP());
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
