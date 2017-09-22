#include <ESP8266WiFi.h>;
const char* ssid = "Tenda_3EF910"; //ชื่อ SSID
const char* password = "gift4321"; // password
void setup()
{
  Serial.begin(115200);
  delay(10);
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) //รอจนกว่าจะเชื่อมต่อสำเร็จ
  {
    delay(500);
    Serial.print("*");
  }

  IPAddress local_ip = {192, 168, 1, 45}; //ฟิกค่า IP
  IPAddress gateway = {192, 168, 1, 1}; //ตั้งค่า IP Gateway
  IPAddress subnet = {255, 255, 255, 0}; //ตั้งค่า Subnet
  WiFi.config(local_ip, gateway, subnet); //setค่าไปยังโมดูล

  Serial.println("");
  Serial.println("WiFi connected"); //แสดงข้อความเชื่อมต่อสำเร็จ
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP()); //แสดงหมายเลข IP ของ NodeMCU
}
void loop() {}
