#include "WifiConnectToThingSpeak.h"


WifiConnectToThingSpeak::WifiConnectToThingSpeak() {}

void WifiConnectToThingSpeak::begin(char* ssid, char* password, String api)
{
    apiKey = api;
    WiFi.begin(ssid, password);
    for(int connectionTimer = 0; connectionTimer < 10; connectionTimer++)
    {
        if(WiFi.status() != WL_CONNECTED)
        {
            Connected = true;
            return;
        }
        else
        {
            Connected = false;
        }
        delay(500);
    }
}

bool WifiConnectToThingSpeak::UploadDataToThingSpeak(float value1)
{
    String inputValues[10] = {String(value1), "", "", "", "", "", "", "", "", ""};
    return UploadDataStringToThingSpeak(inputValues);
}

bool WifiConnectToThingSpeak::UploadDataToThingSpeak(float value1, float value2)
{
    String inputValues[10] = {String(value1), String(value2), "", "", "", "", "", "", "", ""};
    return UploadDataStringToThingSpeak(inputValues);
}

bool WifiConnectToThingSpeak::UploadDataStringToThingSpeak(String inputValues[10])
{
    if(Connected)
    {
        String valueString = "";

        for(int iterator = 0; iterator < 10; iterator++)
        {
            if(inputValues[iterator] != "" )
            {
                valueString += "&field" + String(iterator + 1) + "=" + inputValues[iterator];
            }
        }

        if (client.connect(server,80))
        { // "184.106.153.149" or api.thingspeak.com
            String postStr = apiKey;
            postStr += valueString;
            postStr += "\r\n\r\n";

            client.print("POST /update HTTP/1.1\n");
            client.print("Host: api.thingspeak.com\n");
            client.print("Connection: close\n");
            client.print("X-THINGSPEAKAPIKEY: "+apiKey+"\n");
            client.print("Content-Type: application/x-www-form-urlencoded\n");
            client.print("Content-Length: ");
            client.print(postStr.length());
            client.print("\n\n");
            client.print(postStr);
            client.stop();
            return true;
        }
        return false;
    }
}
