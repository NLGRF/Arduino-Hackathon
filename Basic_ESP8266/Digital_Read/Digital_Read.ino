int sw = D1;
void setup() {
 Serial.begin(9600);
 pinMode(sw, INPUT_PULLUP); 
 // ขา GPIO16 หรือ D0 ไม่มีความสามารถ INPUT_PULLUP
}
void loop() {
 int val = digitalRead(sw);
 Serial.println(val);
 delay(100);
}
