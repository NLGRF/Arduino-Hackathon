#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

const char* ssid = "PEA_HiVE_Demo";
const char* password = "magicalmint636";

const int led = D2;
int state = 0;
String status_led = "OFF";

ESP8266WebServer server(80);
void handle_led() {
  state = server.arg("led").toInt();
  Serial.println(server.arg("led"));
  Serial.println(server.arg("test"));
  status_led = "ON";
  if (state == 1) {
    digitalWrite(led, 1);
    status_led = "ON";
  } else {
    digitalWrite(led, 0);
    status_led = "OFF";
  }
  server.send(200, "text/html", "LED is " + status_led + "<p><a href=?led=1><button> ON </button></a><a href=?led=0><button> OFF </button></a>");
}
void setup(void) {
  Serial.begin(115200);
  Serial.println("");
  pinMode(led, OUTPUT);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  server.on("/", handle_led);
  server.begin();
  Serial.println("HTTP server started");
}

void loop(void) {
  server.handleClient();
}
