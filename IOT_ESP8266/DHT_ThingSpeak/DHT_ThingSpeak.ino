#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266HTTPClient.h>
#include <DHT.h>

#define DHTPIN D2
#define DHTTYPE DHT11

ESP8266WiFiMulti WiFiMulti;
HTTPClient http;
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  Serial.println();
  Serial.println();
  Serial.println();
  Serial.println("Connecting...");
  WiFiMulti.addAP("wifi_ssid", "wifi_password");
  dht.begin();
}
void loop() {
  // wait for WiFi connection
  if ((WiFiMulti.run() == WL_CONNECTED)) {
    float h = dht.readHumidity();
    float t = dht.readTemperature();
    if (isnan(h) || isnan(t))
    {
      Serial.println("Failed to read from DHT sensor!");
      return;
    }
    Serial.println(h);
    Serial.println(t);
    //http://api.thingspeak.com/update?api_key=X7G49NN1XVVVYXM&field1=10&field2=20
    http.begin("http://api.thingspeak.com/update?api_key=X7G49NN1XVV2VYX&field1=" + String(t) + "&field2=" + String(h)); //HTTP
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
  delay(20000);
}
