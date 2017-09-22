int adc = A0;
 void setup() {
 Serial.begin(9600);
 pinMode(adc, INPUT);
 }

void loop() {
 Serial.println(readVolte());
 Serial.println(readVolteAVG());
 delay(1000);
 }

double readVolte() {
 //สูตรคำนวน volte = ค่าที่อ่านได้จาก A0 * Vcc สูงสุดคือ 3.3V / ค่าที่อ่านได้สูงสุดจาก A0 คือ 983;
 int val = analogRead(adc);
 double cal = val * 3.3 / 983;
 return cal;
 }
 double readVolteAVG() {
 //ดัดแปลงจาก readVolte ให้อ่านแบบค่าเฉลี่ย เพื่อความแม่นยำเพิ่มขึ้น
 double sum = 0;
 for (int i = 0; i<10; i++) {
 int val = analogRead(adc);
 double cal = val * 3.3 / 983;
 sum += cal;
 }
 sum = sum / 10;
 return sum;
 }
