#include <AuthClient.h>
#include <MicroGear.h>
#include <ESP8266WiFi.h>


const char* ssid     = "wifi_ssid";
const char* password = "wifi_password";

#define LEDPin D4                                
#define APPID       "ArduinoAll"                  //ชื่อ APPLICATION
#define GEARKEY     "yqFfgKNnapwCJP"             //Key ของอุปกรณ์
#define GEARSECRET  "ebjXFUeFhfj97dtsMqnFZOUo"   //Secret ของอุปกรณ
#define ALIAS       "nodemcu"                     //ชื่อเรียกอุปกรณ์
#define SCOPE       ""

WiFiClient client;
AuthClient *authclient;

MicroGear microgear(client);

void onConnected(char *attribute, uint8_t* msg, unsigned int msglen)
{
  Serial.println("Connected to NETPIE...");
  microgear.setAlias(ALIAS);
}

void onMsghandler(char *topic, uint8_t* msg, unsigned int msglen) // รับข้อความจาก server
{
  Serial.print("Incoming message --> ");
  Serial.print(topic);
  Serial.print(" : ");
  char strState[msglen];
  for (int i = 0; i < msglen; i++)
  {
    strState[i] = (char)msg[i];
    Serial.print((char)msg[i]);
  }
  Serial.println();

  String stateStr = String(strState).substring(0, msglen); // ข้อความที่ได้รับจาก server
  if (stateStr == "ON")
  {
    digitalWrite(LEDPin, HIGH);
    microgear.chat("Sensor/LED", "ON");  // ส่งข้อความถึง server
  }
  else if (stateStr == "OFF")
  {
    digitalWrite(LEDPin, LOW);
    microgear.chat("Sensor/LED", "OFF"); // ส่งข้อความถึง server
  }
}

void setup()
{
  Serial.begin(115200);
  Serial.println("Starting...");
  pinMode(LEDPin, OUTPUT);

  microgear.on(MESSAGE, onMsghandler);
  microgear.on(CONNECTED, onConnected);

  if (WiFi.begin(ssid, password))
  {
    while (WiFi.status() != WL_CONNECTED)
    {
      delay(500);
      Serial.print(".");
    }
    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());

    microgear.resetToken();
    microgear.init(GEARKEY, GEARSECRET, SCOPE);
    microgear.connect(APPID);
  }
}
void loop()
{
  if (microgear.connected())
  {
    microgear.loop();
    Serial.println("connect...");
    microgear.chat("Sensor/Temperature",50); // ส่งข้อความถึง server
    microgear.chat("Sensor/Humidity",65);
    int val = analogRead(A0);
    microgear.chat("Sensor/Volum",val);
  }
  else
  {
    Serial.println("connection lost, reconnect...");
    microgear.connect(APPID);
  }
  delay(100);
}
