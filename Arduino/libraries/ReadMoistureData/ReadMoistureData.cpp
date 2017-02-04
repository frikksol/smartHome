#include "ReadMoistureData.h"

ReadMoistureData::ReadMoistureData(){}

void ReadMoistureData::begin(int inputPowerPin, int inputAnalogDataPin)
{
    powerPin = inputPowerPin;
    analogDataPin = inputAnalogDataPin;

    pinMode(powerPin, OUTPUT);
    pinMode(analogDataPin, INPUT);
}

int ReadMoistureData::GetMoistureReading()
{
    //Turn on moisture measurement unit
    digitalWrite(powerPin, HIGH);
    delay(1000);

    //Measure data
    int moistureReading = GetNewMeasurement();
    for (int measurements = 0; measurements < 10; measurements++)
    {
        delay(300);
        moistureReading = .5 * (moistureReading + GetNewMeasurement());
    }

    //Turn off moisture measurement unit
    digitalWrite(powerPin, LOW);

    return moistureReading;
}

int ReadMoistureData::GetNewMeasurement()
{
    return 1024 - analogRead(analogDataPin); //Result is intverted and between 0 and 1024
}

