#include "ControlWaterPump.h"

ControlWaterPump::ControlWaterPump(){}

void ControlWaterPump::begin(int inputPowerPin)
{
    powerPin = inputPowerPin;
    pinMode(powerPin, OUTPUT);
}

void ControlWaterPump::TurnMotorOnForTimePeriod(int seconds)
{
    digitalWrite(powerPin, HIGH);
    delay(secondsToMilliseconds * seconds);
    digitalWrite(powerPin, LOW);
}

void ControlWaterPump::TurnMotorOnForAmountOfWater(int desiliters)
{
    //TODO: Something causes a bug here
    double timeToHaveMotorRunningInSeconds = desiliters / desilitersPumpedPerSecond;
    digitalWrite(powerPin, HIGH);
    delay(round(desiliters / desilitersPumpedPerSecond));
    digitalWrite(powerPin, LOW);
}