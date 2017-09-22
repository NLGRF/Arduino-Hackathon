#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

const char* ssid = "wifi_ssid";
const char* password = "wifi_password";

const int sensor = A0;

ESP8266WebServer server(80);


void handle_sensor() {
  String val = String(analogRead(A0));
  Serial.println(val);
  server.send(200, "text/html", val);
}

void setup(void) {
  pinMode(A0,INPUT);
  Serial.begin(115200);
 

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
    server.send(200, "text/html", "<html><head> <script src='https://ajax.googleapis.com/ajax/libs/jquery/3.1.1/jquery.min.js'></script> <script> $(document).ready(function () { $('button').click(function () { $('#div1').load('value'); }); setInterval(function () { $('#div1').load('value'); }, 5000); }); </script></head><body> <div id='div1'> <h2>Value Sensor</h2> </div> <button>Refresh</button></body></html>");
  });

  server.on("/value", handle_sensor);

  server.begin();

}

void loop(void) {
  // check for incomming client connections frequently in the main loop:
  server.handleClient();
}
