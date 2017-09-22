#include <ESP8266WiFi.h>

const char* ssid = "ssid";
const char* password = "password";

const char* host = "192.168.1.39";

void setup() {
 Serial.begin(115200);
 delay(10);
 Serial.println();
 Serial.println();
 Serial.print("Connecting to ");
 Serial.println(ssid);

WiFi.begin(ssid, password);

while (WiFi.status() != WL_CONNECTED) {
 delay(500);
 Serial.print(".");
 }

Serial.println("");
 Serial.println("WiFi connected");
 Serial.println("IP address: ");
 Serial.println(WiFi.localIP());

}//end setup

void loop() {
 delay(1000);

Serial.print("Connecting to ");
 Serial.println(host);

// Use WiFiClient class to create TCP connections
 WiFiClient Client;
 const int httpPort = 80;
 if (!Client.connect(host, httpPort)) {
 Serial.println("Connection failed");
 return;
 }

// We now create a URI for the request
 String url = "/nodemcu/index.php?name=arduinoall";
 Serial.print("Requesting URL: ");
 Serial.println(host + url);


 // This will send the request to the server
 //Client.print(String("GET ") + url +" HTTP/1.1\r\n" + "Host: " + host + "\r\n" + "Connection: close\r\n\r\n");
 Client.print("GET ");
 Client.print(url);
 Client.println(" HTTP/1.1");
 Client.print("Host: ");
 Client.println(host);
 Client.println("Connection: close");
 Client.println();
 delay(500);

// Read all the lines of the reply from server and print them to Serial
 while (Client.available()) {
 String line = Client.readStringUntil('\r');
 Serial.println(line);
 }
 Serial.println("");
 Serial.println("Waiting for next try...");
 Serial.println("");
 delay(30000);
}
