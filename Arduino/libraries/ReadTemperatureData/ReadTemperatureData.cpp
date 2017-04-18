#include "ReadTemperatureData.h"

ReadTemperatureData::ReadTemperatureData(){}

void ReadTemperatureData::begin(int inputPowerPin, int inputAnalogDataPin)
{
    powerPin = inputPowerPin;
    pinMode(powerPin, OUTPUT);
}

void ReadTemperatureData::UpdateReadings()
{
    //Turn on moisture measurement unit
    digitalWrite(powerPin, HIGH);
    delay(2000);
    if (!bmp.begin())
    {
        Serial.println("Could not find a valid BMP280 sensor, check wiring!");
    }
    delay(1000);

    //Measure data
    int humidity = bmp.readPressure(); //GetNewHumidityMeasurement();
    int temperature = bmp.readTemperature(); //GetNewHumidityMeasurement();

    for (int measurements = 0; measurements < 10; measurements++)
    {
        delay(300);
        humidity = .5 * (humidity + bmp.readPressure());
        temperature = .5 * (temperature + bmp.readTemperature());
    }

    Humidity = humidity;
    Temperature = temperature;

    //Turn off moisture measurement unit
    digitalWrite(powerPin, LOW);
}
