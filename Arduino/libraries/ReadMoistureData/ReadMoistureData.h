#include <Arduino.h>

class ReadMoistureData
{
public:
    ReadMoistureData();
    void begin(int powerPin, int analogDataPin);
    int GetMoistureReading();

private:
    int GetNewMeasurement();
    int powerPin{ 0 };
    int analogDataPin{ 0 };
};
