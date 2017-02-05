#include <DHT.h>

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
    const int dhtType{DHT11};
};
