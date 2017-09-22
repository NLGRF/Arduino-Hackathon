#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

const char* ssid = "wifi_ssid";
const char* password = "wifi_password";

const int led = D2;
int state = 0;
String status_led = "OFF";

ESP8266WebServer server(80);

void handle_hello() {

  String value = server.arg("a");
  String value2 = server.arg("b");
  server.send(200, "text/html", "A = " + value + " : B = " + value2);
  Serial.println(value + ":" + value2);
}

void handle_led() {
  state = server.arg("led").toInt();
  status_led = "ON";
  if (state == 1) {
    digitalWrite(led, 1);
    status_led = "ON";
  } else {
    digitalWrite(led, 0);
    status_led = "OFF";
  }
  server.send(200, "text/plain", "LED is " + status_led);
}

void handle_control() {
  String html = "LED Status = " + status_led;
  server.send(200, "text/html", "LED is " + status_led + "<p><a href=led?led=1><button> ON </button></a><a href=led?led=0><button> OFF </button></a>");
}

void setup(void) {
  Serial.begin(115200);
  Serial.println("");
  pinMode(led, OUTPUT);

  // Connect to WiFi network
  WiFi.begin(ssid, password);

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  server.on("/", []() {
    server.send(200, "text/html", "<h1>ESP8266 NodeMCU Tutor</h1>");
  });


  server.on("/led", handle_led);
  server.on("/hello", handle_hello);
  server.on("/control", handle_control);

  // Start the server
  server.begin();
  Serial.println("HTTP server started");
}

void loop(void) {
  // check for incomming client connections frequently in the main loop:
  server.handleClient();
}
