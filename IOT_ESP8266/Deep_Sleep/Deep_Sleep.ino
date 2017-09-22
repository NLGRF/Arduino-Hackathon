#define SECONDS_DS(seconds)  ((seconds)*1000000UL)
void setup() {
  Serial.begin(115200);
  Serial.println("Setup...");
}
void loop() {
  delay(1000);
  Serial.println("Sleeping");
  ESP.deepSleep(SECONDS_DS(5));
}
