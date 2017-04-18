#include <WifiConnectToThingSpeak.h>
#include <ReadTemperatureData.h>
#include <ReadMoistureData.h>
#include <ControlWaterPump.h>

//Initializing data objects
WifiConnectToThingSpeak wifi;
ReadTemperatureData temperatureData;
ReadMoistureData moistureData;
ControlWaterPump waterPump;

//Constants
const int oneMinute = 60 * 1000;
const int moisturePowerPin = 12;
const int moistureDataPin = A0;
const int pumpPowerPin = 13;
const int temperaturePowerPin = 14;
const int limitForPlantDryness = 450; //TODO Do this a bit more sophisticated

void setup() {
  Serial.begin(115200);
  Serial.println("");

  //Wifi Logon TODO: Should be done in a less shitty way
  Serial.println("Connecting to WiFi");
  String apiKey = "XXXXXXXXXXXXXXXX";
  char* ssid = "ssid";
  char* password = "password";

  //Running begin functions. Arduino likes to do it this way...
  //TODO: No check if any of these fail
  wifi.begin(ssid, password, apiKey);
  temperatureData.begin(temperaturePowerPin, moistureDataPin);
  moistureData.begin(moisturePowerPin, moistureDataPin);
  waterPump.begin(pumpPowerPin);
  
  delay(50);
}

void loop() {

  //Temperature
  temperatureData.UpdateReadings();
  float humidityReading = temperatureData.Humidity;  
  float temperatureReading = temperatureData.Temperature;
  Serial.print("Humidity Measurement Reading: ");
  Serial.println(humidityReading);
  Serial.print("Temperature Measurement Reading: ");
  Serial.println(temperatureReading);

  //Moisture
  int moistureReading = moistureData.GetMoistureReading();
  Serial.print("Moisture Measurement Reading: ");
  Serial.println(moistureReading);

  //Water Pump
  if (moistureReading < limitForPlantDryness)
  {
    Serial.println("Plant is dry. Watering now");
    waterPump.TurnMotorOnForTimePeriod(1);
  }

  //Upload data
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
