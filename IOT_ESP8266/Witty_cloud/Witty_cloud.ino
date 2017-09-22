int ldr = A0;
int r = 15;
int g = 12;
int b = 13;
int button = 4;
int stage = 0;
void setup() {
  pinMode(ldr, INPUT);
  pinMode(button, INPUT);
  pinMode(r, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(b, OUTPUT);
  for (int i = 0; i < 3; i++) {
    nextState();
    delay(500);
  }
  led(0, 0, 0);

}
void loop() {
  Serial.begin(115200);
  int ldr_value = analogRead(ldr);
  int btn = digitalRead(button);
  Serial.print("LDR is ");
  Serial.println(ldr_value);

  if (btn == 0) {
    Serial.println("Button press");
    setLED(ldr_value);
  } else {
    led(0, 0, 0);
  }
  delay(200);
}
void led(int red, int green, int blue) {
  digitalWrite(r, red);
  digitalWrite(g, green);
  digitalWrite(b, blue);
}
void nextState() {
  if (stage == 0) {
    led(1, 0, 0);
  } else if (stage == 1) {
    led(0, 1, 0);
  } else if (stage == 2) {
    led(0, 0, 1);
  } else if (stage > 2) {
    stage = -1;
    led(0, 0, 0);
  }
  stage++;
}
void setLED(int value) {
  if (value > 550) {
    led(1, 0, 0);
  } else if (value > 300) {
    led(0, 1, 0);
  } else {
    led(0, 0, 1);
  }
}
