#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266HTTPClient.h>

ESP8266WiFiMulti WiFiMulti;
HTTPClient http;
void setup() {
  Serial.begin(115200);
  Serial.println();
  Serial.println();
  Serial.println();

  Serial.println("Connecting...");
  WiFiMulti.addAP("ssid", "password");
}
void loop() {
  // wait for WiFi connection
  if ((WiFiMulti.run() == WL_CONNECTED)) {

    http.begin("http://www.arduinoall.net/arduino-tutor/code/client.php?name=Arduinoall"); //HTTP
    int httpCode = http.GET();
    if (httpCode > 0) {
      Serial.printf("[HTTP] GET... code: %d\n", httpCode);
      if (httpCode == HTTP_CODE_OK) {
        String payload = http.getString();
        Serial.println(payload);
      }
    } else {
      Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
    }
    http.end();
  }
  delay(5000);
}
