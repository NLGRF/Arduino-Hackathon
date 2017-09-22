#include <SoftwareSerial.h>
//Code By ArduinoALL
SoftwareSerial ArduinoSerial(3, 2); // RX, TX
void setup() {
  Serial.begin(115200);
  ArduinoSerial.begin(4800);

  pinMode(13, OUTPUT);
}
void loop() {
  while (ArduinoSerial.available() > 0) {
    float val = ArduinoSerial.parseFloat();
    if (ArduinoSerial.read() == '\n') {
      if (val == 0xA0) {
        int A0 = analogRead(A0);
        ArduinoSerial.print(A0);
        ArduinoSerial.print("\n");
      }
    }
  }
  delay(100);
}
