int led = D1;
 void setup() {
 pinMode(led, OUTPUT);
 }

void loop() {
 analogWrite(led,20);
 delay(1000);
 analogWrite(led,300);
 delay(1000);
 analogWrite(led,1023);
 delay(1000);
}
