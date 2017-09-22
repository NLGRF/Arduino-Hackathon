#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

// Config Firebase
#define FIREBASE_HOST "nodemcu-dfc8e.firebaseio.com"
#define FIREBASE_AUTH "sEcvkstjpTArjiq1rHaZly5iYHUfcL9Ym2FcqBMP"

// Config connect WiFi
#define WIFI_SSID "Tenda_3EF910"
#define WIFI_PASSWORD "gift4321"

void setup() {
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
  Firebase.push("/a/b/c", 50);
  if (Firebase.failed()) {
      Serial.print("push /number failed:");
      Serial.println(Firebase.error());  
      return;
  }  
  
  delay(30000);
}
