#include <Wire.h>
#include <Adafruit_BMP280.h>

class ReadTemperatureData
{
public:
    ReadTemperatureData();
    void begin(int inputPowerPin, int inputAnalogDataPin);
    void UpdateReadings();
    float Humidity{ 0 };
    float Temperature{ 0 };

private:
    int GetNewMeasurement();
    int powerPin{ 0 };
    int dataPin{ 0 };
    Adafruit_BMP280 bmp;
};
