#include <Wire.h>
int LED = 13;
int x = 0;
void setup() {
  pinMode(LED, OUTPUT);
  Wire.begin(9);
  Wire.onReceive(receiveEvent);
}
void receiveEvent(int bytes) {
  x = Wire.read();
}
void loop() {
  if (x == 1) {
    digitalWrite(LED, 1);
  } else if (x == 0) {
    digitalWrite(LED, 0);
  }
}
