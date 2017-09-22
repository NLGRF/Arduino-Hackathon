int adc = A0;
void setup() {
  Serial.begin(9600);
  pinMode(adc, INPUT);
}

void loop() {
  int val = analogRead(adc);
  Serial.println(val);
  delay(1000);
}
