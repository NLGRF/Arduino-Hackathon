#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

const char* ssid = "Tenda_3EF910";
const char* password = "gift4321";

const int led = D2;
int state = 0;

ESP8266WebServer server(80);
void handle_led() {
  state = server.arg("speed").toInt();
  analogWrite(D2, state);
  server.send(200, "text/html", "<h1>speed is " + String(state) + "/1024</h1>");
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
