int led1 = 4; // เลข 4 หรือชื่อเรียกคือ D2
void setup() {
  pinMode(led1, OUTPUT);
}

void loop() {
  digitalWrite(led1, 1);
  delay(1000);
  digitalWrite(D2, 0);
  delay(1000);
}
