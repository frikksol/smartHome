#include <WifiConnectToThingSpeak.h>

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  String apiKey = "6CWX08BRLJBPW7WE";
  char* ssid = "Borberg";
  char* password = "MartineErDigg";
  WifiConnectToThingSpeak wifi;
  wifi.begin(ssid, password, apiKey);
  wifi.UploadDataToThingSpeak(42);
  delay(20000);
}
