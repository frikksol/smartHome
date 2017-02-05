#include "ReadTemperatureData.h"

ReadTemperatureData::ReadTemperatureData(){}

void ReadTemperatureData::begin(int inputPowerPin, int inputAnalogDataPin)
{
    powerPin = inputPowerPin;
    dataPin = inputAnalogDataPin;

    pinMode(powerPin, OUTPUT);
    pinMode(dataPin, INPUT);

}

void ReadTemperatureData::UpdateReadings()
{
    //Turn on moisture measurement unit
    digitalWrite(powerPin, HIGH);
    DHT dht(dataPin, dhtType);
    dht.begin();
    delay(1000);

    //Measure data
    int humidity = dht.readHumidity(); //GetNewHumidityMeasurement();
    int temperature = dht.readTemperature(); //GetNewHumidityMeasurement();

    for (int measurements = 0; measurements < 10; measurements++)
    {
        delay(300);
        humidity = .5 * (humidity + dht.readHumidity());
        temperature = .5 * (temperature + dht.readTemperature());
    }

    Humidity = humidity;
    Temperature = temperature;

    //Turn off moisture measurement unit
    digitalWrite(powerPin, LOW);
}
