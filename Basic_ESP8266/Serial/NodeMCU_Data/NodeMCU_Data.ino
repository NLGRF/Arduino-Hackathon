#include <ESP8266WiFi.h>
#include <SoftwareSerial.h>
//Code By ArduinoALL
SoftwareSerial NodeSerial(D2, D3); // RX | TX
void setup() {
  pinMode(D2, INPUT);
  pinMode(D3, OUTPUT);
  Serial.begin(115200);
  NodeSerial.begin(4800);
}
void loop() {
  NodeSerial.print(0xA0);
  NodeSerial.print("\n");

  while (NodeSerial.available() > 0) {
    float val = NodeSerial.parseFloat();
    if (NodeSerial.read() == '\n') {
      Serial.println(val);
    }
  }
  delay(100);
}
