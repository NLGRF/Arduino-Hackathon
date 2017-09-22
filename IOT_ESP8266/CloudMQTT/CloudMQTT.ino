// Code By ArduinoALL
#include <ESP8266WiFi.h>
#include <PubSubClient.h>

const char* ssid = "wifi_ssid"; // แก้ ssid
const char* password = "wifi_password"; // แก้ password


// Config MQTT Server
const char * topic = "/server"; // topic ชื่อ /server
#define mqtt_server "m13.cloudmqtt.com" // server
#define mqtt_port 18957   // เลข port
#define mqtt_user "rdrldub" // user
#define mqtt_password "gGhQj5S39_X" // password


#define LED_PIN D4
char *led_status = "OFF";

WiFiClient espClient;
PubSubClient client(espClient);

void setup() {
  // เชื่อมต่อ network
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(115200);
  delay(10);
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
  // จบการเชื่อมต่อ network

  client.setServer(mqtt_server, mqtt_port); // เชื่อมต่อ mqtt server
  client.setCallback(callback); // สร้างฟังก์ชันเมื่อมีการติดต่อจาก mqtt มา
}

void loop() {
  if (!client.connected()) {
    Serial.print("MQTT connecting...");
    if (client.connect("ESP8266Client", mqtt_user, mqtt_password)) { // ถ้าเชื่อมต่อ mqtt สำเร็จ
      client.subscribe(topic); // ชื่อ topic ที่ต้องการติดตาม
      Serial.println("connected");
    }
    // ในกรณีเชื่อมต่อ mqtt ไม่สำเร็จ
    else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      delay(5000); // หน่วงเวลา 5 วินาที แล้วลองใหม่
      return;
    }
  }
  client.loop();
}

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message from ");
  Serial.println(topic);
  String msg = "";
  int i = 0;
  while (i < length) {
    msg += (char)payload[i++]; // อ่านข้อความจาก topic ที่ส่งมา
  }
  Serial.print("receive ");
  Serial.println(msg); // แสดงข้อความที่ได้รับจาก topic

  if (msg == "on") { // ถ้า topic ส่งคำว่า on
    digitalWrite(LED_PIN, 1);
    led_status = "NodeMCU : LED ON";
    client.publish("/NodeMCU", led_status); // ส่งข้อความกลับไปที่ topic คือ ชื่ออุปกรณ์ที่ส่ง , ข้อความ
  } else if (msg == "off") {
    digitalWrite(LED_PIN, 0);
    led_status = "NodeMCU : LED OFF";
    client.publish("/NodeMCU", led_status);
  }else if(msg=="status"){
    client.publish("/NodeMCU", led_status);
  }
  // แสดงข้อความตอบกลับที่ส่งไปที่ topic
  if (led_status != "") {
    Serial.print("Answer ");
    Serial.println(led_status);
  }
}
