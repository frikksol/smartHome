#include <WifiConnectToThingSpeak.h>

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  String apiKey = "XXXXXXXXXXXXXXXX";
  char* ssid = "ssid";
  char* password = "password";
  WifiConnectToThingSpeak wifi;
  wifi.begin(ssid, password, apiKey);
  wifi.UploadDataToThingSpeak(42);
  delay(20000);
}
