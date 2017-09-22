void setup() {
 Serial.begin(115200);
}

void loop() {
 if (digitalRead(D1) == 1) {
 Serial.println("No ");
 }else{
 Serial.println("Detect");
 }
 delay(1000);
}
