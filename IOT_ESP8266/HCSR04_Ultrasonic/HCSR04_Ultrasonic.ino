#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

const char* ssid = "wifi_ssid";
const char* password = "wifi_password";


ESP8266WebServer server(80);
long duration, cm;
const int pingPin = D1;
int inPin = D2;

void handle_sensor() {

  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);
  pinMode(inPin, INPUT);
  duration = pulseIn(inPin, HIGH);
  cm = microsecondsToCentimeters(duration);
  server.send(200, "text/html", String(cm) + " CM");
}

void setup(void) {
  Serial.begin(115200);

  // Connect to WiFi network
  WiFi.begin(ssid, password);

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  server.on("/", []() {
    server.send(200, "text/html", "<html><head> <script src='https://ajax.googleapis.com/ajax/libs/jquery/3.1.1/jquery.min.js'></script> <script> $(document).ready(function () { $('button').click(function () { $('#div1').load('value'); }); setInterval(function () { $('#div1').load('value'); }, 500); }); </script></head><body><img src='http://www.arduinoall.net/arduino-tutor/wp-content/uploads/2016/12/1.png'><div id='div1'><h1>Value Sensor</h1> </div></h1> <button>Refresh</button></body></html>");
  });

  server.on("/value", handle_sensor);

  server.begin();

}
long microsecondsToCentimeters(long microseconds)
{
  return microseconds / 29 / 2;
}

void loop(void) {
  // check for incomming client connections frequently in the main loop:
  server.handleClient();
}
