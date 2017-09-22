/*
 SD Card
 CS – D8
 SCK – D5
 MOSI – D7
 MISO – D6
 VCC – 3.3V
 GND – GND
 ==========
 DHT
 1 - 3.3V
 2 - D2
 4 - GND
 R 4.7K ต่อคร่อมขา 1 และ 2
*/
#include <SPI.h>
#include <SD.h>
#include <DHT.h>
#include <ESP8266WiFi.h>
#include <time.h>

#define DHTPIN D2
#define DHTTYPE DHT11 // DHT 11
//#define DHTTYPE DHT22 // DHT 22 (AM2302), AM2321
//#define DHTTYPE DHT21 // DHT 21 (AM2301)

const char* ssid = "wifi_ssid"; //ใส่ชื่อ SSID Wifi
const char* password = "wifi_password"; //ใส่รหัสผ่าน

int timezone = 7 * 3600; //ตั้งค่า TimeZone ตามเวลาประเทศไทย
int dst = 0; //กำหนดค่า Date Swing Time


DHT dht(DHTPIN, DHTTYPE);
const int chipSelect = 4;

void setup() {
 // Open serial communications and wait for port to open:
 Serial.begin(115200);
 while (!Serial) {
 ; // wait for serial port to connect. Needed for native USB port only
 }


 Serial.print("Initializing SD card...");

if (!SD.begin(chipSelect)) {
 Serial.println("Card failed, or not present");
 }
 Serial.println("SD Card OK");
 dht.begin();

WiFi.mode(WIFI_STA); //เชื่อมต่อ Wifi
 WiFi.begin(ssid, password);
 Serial.println("\nConnecting to WiFi");
 while (WiFi.status() != WL_CONNECTED) {
 Serial.print("*");
 delay(1000);
 }
 configTime(timezone, dst, "pool.ntp.org", "time.nist.gov"); //ดึงเวลาจาก Server
 Serial.println("\nLoading time");
 while (!time(nullptr)) {
 Serial.print("*");
 delay(1000);
 }
 Serial.println("Load time OK");
 Serial.println("");
}


void loop() {

time_t now = time(nullptr);
 struct tm* p_tm = localtime(&now);


 String now_time = "";
 now_time = now_time + p_tm->tm_hour;
 now_time = now_time + ":";
 now_time = now_time + p_tm->tm_min;
 now_time = now_time + ":";
 now_time = now_time + p_tm->tm_sec;
 //Serial.println(now_time);

String now_day = "";
 now_day = now_day + p_tm->tm_mday;
 now_day = now_day + "-";
 now_day = now_day + (p_tm->tm_mon + 1);
 now_day = now_day + "-";
 now_day = now_day + (p_tm->tm_year + 2443);
 //Serial.println(now_day);
 String dateTime = now_day + " ";
 dateTime = dateTime + now_time;
 //Serial.println(dateTime);

float h = dht.readHumidity(); // ความชื้น
 float t = dht.readTemperature(); // อุณหภูมิ เซลเซียส
 //String dataString = dt + " Temp = " + t + " Humidity = " + h;
 String sensor = " Sensor : ";
 sensor = sensor + t;
 sensor = sensor + " *C ";
 sensor = sensor + " Humidity ";
 sensor = sensor + h;
 //Serial.println(sensor);

String dataString = dateTime + sensor;
 //Serial.println(dataString);
 File dataFile = SD.open("datalog.txt", FILE_WRITE);


 if (dataFile) {
 dataFile.println(dataString);
 dataFile.close();
 Serial.println(dataString);
 }
 else {
 Serial.println("error opening datalog.txt");
 }
 delay(3000);
}
