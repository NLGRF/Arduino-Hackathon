#include <ESP8266WiFi.h>
#include <time.h>

const char* ssid = "ssid"; //ใส่ชื่อ SSID Wifi
const char* password = "password"; //ใส่รหัสผ่าน

int timezone = 7 * 3600; //ตั้งค่า TimeZone ตามเวลาประเทศไทย
int dst = 0; //กำหนดค่า Date Swing Time

void setup()
{
  Serial.begin(115200);
  Serial.setDebugOutput(true);

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
  Serial.println("");
}

void loop()
{
  //configTime(timezone, dst, "pool.ntp.org", "time.nist.gov"); //แสดงเวลาปัจจุบัน
  time_t now = time(nullptr);
  struct tm* p_tm = localtime(&now);

  Serial.print(p_tm->tm_hour);
  Serial.print(":");
  Serial.print(p_tm->tm_min);
  Serial.print(":");
  Serial.print(p_tm->tm_sec);
  Serial.println("");
  delay(1000);
}

//struct tm {
// int tm_sec; /* วินาที, range 0 to 59 */
// int tm_min; /* นาที, range 0 to 59 */
// int tm_hour; /* ชั่วโมง, range 0 to 23 */
// int tm_mday; /* วันที่, range 1 to 31 */
// int tm_mon; /* เดือน, range 0 to 11 */
// int tm_year; /* ปีคริสศักราช ตั้งแต่ 1900 */
// int tm_wday; /* วัน, range 0 to 6 */
// int tm_yday; /* วันใน 1 ปี, range 0 to 365 */
// int tm_isdst; /* daylight saving time */
// };

