void setup() {
  pinMode(D1,OUTPUT);
  pinMode(D2,OUTPUT);
}

void loop() {
  analogWrite(D1,0);
  analogWrite(D2,1023);
  delay(3000);
  analogWrite(D1,1023);
  analogWrite(D2,0);
  delay(3000);
  analogWrite(D1,500);
  analogWrite(D2,0);
  delay(3000);
  analogWrite(D1,0);
  analogWrite(D2,0);
  delay(3000);
}
