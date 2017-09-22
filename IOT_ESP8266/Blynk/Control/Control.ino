#define BLYNK_PRINT Serial    // Comment this out to disable prints and save space
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "a9d2e8623f69416e9f6370821ac7985";

void setup()
{
  Serial.begin(115200);
  Blynk.begin(auth, "wifi_ssid", "wifi_password");
}

void loop()
{
  Blynk.run();
  int value1 = 50;
  int value2 = 45;
  Blynk.virtualWrite(10,value1);
  Blynk.virtualWrite(11,value2);
}
