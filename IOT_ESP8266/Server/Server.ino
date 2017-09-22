#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

const char* ssid = "wifi_ssid";
const char* password = "wifi_password";
ESP8266WebServer server(80);

void handle_index() {
  server.send(200, "text/html", "<h1>Hello World ESP8266</h1>");
}

void setup(void) {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println(".");
  }
  Serial.println(WiFi.localIP());

  server.on("/", handle_index);
  server.begin();
}
void loop(void) {
  server.handleClient();
}
