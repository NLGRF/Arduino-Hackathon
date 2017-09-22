#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

// Config Firebase
#define FIREBASE_HOST "nodemcu-dfc8e.firebaseio.com"
#define FIREBASE_AUTH "sEcvkstjpTArjiq1rHaZly5iYHUfcL9Ym2FcqBMP"

// Config connect WiFi
#define WIFI_SSID "Tenda_3EF910"
#define WIFI_PASSWORD "gift4321"

int pin_Led = D4;
void setup() {
  pinMode(pin_Led, OUTPUT);
  Serial.begin(9600);
  WiFi.mode(WIFI_STA);
  // connect to wifi.
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}

void loop() {

  FirebaseObject data = Firebase.get("/a/c");
  // data.getInt("path/path");
  int a = data.getInt("a");
  int ba = data.getInt("/b/a");
  int bb = data.getInt("/b/b");
  if (Firebase.failed()) {
    Serial.println(Firebase.error());
    return;
  } else {
    Serial.print("A = ");
    Serial.println(a);

    Serial.print("BA = ");
    Serial.println(ba);

    Serial.print("BB = ");
    Serial.println(bb);
  }
  delay(10000);
}
