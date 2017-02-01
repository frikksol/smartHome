#include <WifiConnectToThingSpeak.h>

WifiConnectToThingSpeak wifi;


void setup() {
  Serial.begin(115200);
  Serial.println("");
  Serial.println("Connecting to WiFi");
  String apiKey = "6CWX08BRLJBPW7WE";
  String apiKey = "XXXXXXXXXXXXXXXX";
  char* ssid = "ssid";
  char* password = "password";
  wifi.begin(ssid, password, apiKey);
  delay(50);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  
  if (wifi.UploadDataToThingSpeak(42))
  {
    Serial.println("Value uploaded to ThingSpeak Successfully");
  }
  else
  {
    Serial.println("ERROR while uploding value to ThingSpeak!");
  }
  delay(20000);
}
