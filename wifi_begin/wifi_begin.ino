/*********************************
STA STAtion mode
AP  AccessPoint

*********************************/

#include "Arduino.h"
// #include "WiFi.h"
#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>

#define WIFI_NETWORK "STAR"
#define WIFI_PASSWORD "ZE5VY!Yf"
#define WIFI_TIMEOUT_MS 20000

ESP8266WiFiMulti WiFiMulti;

void setup()
{
  Serial.begin(115200);
  connect_to_wifi();

}
void loop()
{


}
void connect_to_wifi(void)
{
  Serial.println("Connnecting to wifi");

  WiFi.mode(WIFI_AP);
  WiFi.begin(WIFI_NETWORK,WIFI_PASSWORD);
  uint32_t temp_time = millis();

  while (WiFi.status() != WL_CONNECTED && (millis()-temp_time) <  WIFI_TIMEOUT_MS)
  {
    Serial.print(".");
    delay(200);
  }

  if(WiFi.status() != WL_CONNECTED)
  {
    Serial.println("Failed!");
    return;
  }

  Serial.println("Connected");
  Serial.println(WiFi.localIP());

}
