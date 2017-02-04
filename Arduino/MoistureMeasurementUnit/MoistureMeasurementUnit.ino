#include <WifiConnectToThingSpeak.h>
#include <ReadMoistureData.h>

WifiConnectToThingSpeak wifi;
ReadMoistureData moistureData;

const int oneMinute = 60000;
const int powerPin = 12;
const int dataPin = A0;

void setup() {
  Serial.begin(115200);
  Serial.println("");

  //Connect WiFi
  Serial.println("Connecting to WiFi");
  String apiKey = "XXXXXXXXXXXXXXXX";
  char* ssid = "ssid";
  char* password = "password";
  wifi.begin(ssid, password, apiKey);
  moistureData.begin(powerPin, dataPin);
  
  delay(50);
}

void loop() {

  int moistureReading = moistureData.GetMoistureReading();
  Serial.print("Moisture Measurement Reading: ");
  Serial.println(moistureReading);
  
  if (wifi.UploadDataToThingSpeak(moistureReading))
  {
    Serial.println("Value uploaded to ThingSpeak Successfully");
  }
  else
  {
    Serial.println("ERROR while uploding value to ThingSpeak!");
  }
  delay(oneMinute);
}
