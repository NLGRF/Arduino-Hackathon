//Demo Code By ArduinoALL
#include <Wire.h>
void setup()
{
  Wire.begin();
}
void loop()
{
  Wire.beginTransmission(9);
  Wire.write(0);
  Wire.endTransmission();
  delay(1000);

  Wire.beginTransmission(9);
  Wire.write(1);
  Wire.endTransmission();
  delay(1000);
}
