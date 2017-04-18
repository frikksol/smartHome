#include <Arduino.h>

class ControlWaterPump
{
public:
    ControlWaterPump();
    void begin(int inputPowerPin);
    void TurnMotorOnForTimePeriod(int seconds);
    void TurnMotorOnForAmountOfWater(int desiliters);

private:
    int powerPin{ 0 };
    const int secondsToMilliseconds = 1000;
    const int desilitersPumpedPerSecond = 80*0.00278; //Pump can deliver 80L/H, converted to dl/Secs
};
