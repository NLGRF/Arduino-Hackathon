#include <ESP8266WiFi.h>
const char* ssid = "wifi_ssid"; // ชื่อ WiFi Access Point ที่ต้องการเชื่อมต่อ
const char* password = "wifi_password"; //รหัสผ่าน Access Point
int led = 2;
void setup()
{
  pinMode(led, OUTPUT);
  Serial.begin(115200); //ตั้งค่าใช้งาน serial ที่ baudrate 115200
  delay(10);
  Serial.print("Connecting to "); //แสดงข้อความ “Connecting to”
  Serial.println(ssid); //แสดงข้อความ ชื่อ SSID

  WiFi.begin(ssid, password); // สั่งให้เชื่อมต่อกับ AP
  //WiFi.begin(ssid); // กรณีเชื่อมต่อแบบไม่มี password

  while (WiFi.status() != WL_CONNECTED) //รอจนกว่าจะเชื่อมต่อสำเร็จ
  {
    delay(500);
    Serial.print("*");
  }
  Serial.println("");
  Serial.println("WiFi connected"); //แสดงข้อความเชื่อมต่อสำเร็จ
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP()); //แสดงหมายเลข IP NodeMCU ของเรา
}
void loop() {
  digitalWrite(led, 1);
  delay(1000);
  digitalWrite(led, 0);
  delay(1000);
}
