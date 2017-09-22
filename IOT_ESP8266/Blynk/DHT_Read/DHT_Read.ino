#define BLYNK_PRINT Serial    // Comment this out to disable prints and save space
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include "DHT.h"

#define DHTPIN D2
#define DHTTYPE DHT11 // DHT 11
DHT dht(DHTPIN, DHTTYPE);

char auth[] = "a9d2e863f69416e9f6708261ac7985";

void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, "wifi_ssid", "gift4321");
  Serial.println("DHTxx test!");
  dht.begin();
}

void loop()
{
  Blynk.run();

  float h = dht.readHumidity(); // ความชื้น
  float t = dht.readTemperature(); // อุณหภูมิ เซลเซียส

  // if (isnan(h) || isnan(t) || isnan(f)) {
  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.print(" C ");
  //  Serial.print(f);
  //  Serial.println(" F\t");

  Blynk.virtualWrite(10, t); //virtual pin
  Blynk.virtualWrite(11, h); // virtual pin

  delay(2000);
}
