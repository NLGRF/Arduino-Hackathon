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
  ArduinoOnPin(13);
  delay(1000);
  ArduinoOffPin(13);
  delay(1000);
}

void ArduinoOnPin(int pin) {
  if (pin == 13) {
    NodeSerial.print(0x113); // 1-13 แปลว่า เปิด-ขา 13
    NodeSerial.print("\n");
  }
}

void ArduinoOffPin(int pin) {
  if (pin == 13) {
    NodeSerial.print(0x013); // 0-13 แปลว่า ปิด-ขา 13
    NodeSerial.print("\n");
  }
}
