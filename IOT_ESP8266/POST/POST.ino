#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266HTTPClient.h>

ESP8266WiFiMulti WiFiMulti;
HTTPClient http;
void setup() {
  Serial.begin(115200);
  WiFiMulti.addAP("ssid", "password");
  Serial.println("\n\n\nNetwork Connecting\n");
}
void loop() {
  if ((WiFiMulti.run() == WL_CONNECTED)) {
    http.begin("http://www.arduinoall.net/arduino-tutor/code/client.php"); //HTTP
    http.addHeader("Content-Type", "application/x-www-form-urlencoded");
    int httpCode = http.POST("name=ArduinoALL&val=50");
    if (httpCode > 0) {
      Serial.printf("[HTTP] POST... code: %d\n", httpCode);
      if (httpCode == HTTP_CODE_OK) {
        String payload = http.getString();
        Serial.println(payload);
      }
    } else {
      Serial.printf("[HTTP] POST... failed, error: %s\n", http.errorToString(httpCode).c_str());
    }
    http.end();
  }
  delay(5000);
}
