#include <WifiConnectToThingSpeak.h>
#include <ReadTemperatureData.h>

WifiConnectToThingSpeak wifi;
ReadTemperatureData temperatureData;

const int oneMinute = 60000;
const int powerPin = 12;
const int dataPin = 13;

void setup() {
  Serial.begin(115200);
  Serial.println("");

  //Connect WiFi
  Serial.println("Connecting to WiFi");
  String apiKey = "XXXXXXXXXXXXXXXX";
  char* ssid = "ssid";
  char* password = "password";
  wifi.begin(ssid, password, apiKey);
  temperatureData.begin(powerPin, dataPin);
  
  delay(50);
}

void loop() {

  temperatureData.UpdateReadings();
  float humidityReading = temperatureData.Humidity;  
  float temperatureReading = temperatureData.Temperature;
  Serial.print("Humidity Measurement Reading: ");
  Serial.println(humidityReading);
  Serial.print("Temperature Measurement Reading: ");
  Serial.println(temperatureReading);
  
  if (wifi.UploadDataToThingSpeak(humidityReading, temperatureReading))
  {
    Serial.println("Values uploaded to ThingSpeak Successfully");
  }
  else
  {
    Serial.println("ERROR while uploding values to ThingSpeak!");
  }
  delay(oneMinute);
}
