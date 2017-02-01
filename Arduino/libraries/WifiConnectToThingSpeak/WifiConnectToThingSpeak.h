#include <ESP8266WiFi.h>
#include <Arduino.h>

class WifiConnectToThingSpeak
{
public:
    WifiConnectToThingSpeak();
    void begin(char* ssid, char* password, String api);
    bool UploadDataToThingSpeak(float value1);
    bool UploadDataToThingSpeak(float value1, float value2);
    bool Connected;

private:
    bool UploadDataStringToThingSpeak(String inputValues[10]);
    WiFiClient client;
    String apiKey;
    const char* server = "api.thingspeak.com";
};
