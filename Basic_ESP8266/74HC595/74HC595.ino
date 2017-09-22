int latchPin = D3; // 12 ST_CP storage resister clock input
int clockPin = D2; // 11 SC_CP Shift register clock input
int dataPin = D1; //14  Serial data input
long randNumber;
void setup()
{
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
}
void loop()
{
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, 0b11011100); // 0xff // เรียงขา 0b 76543210
  digitalWrite(latchPin, HIGH);
  delay(500);
}
