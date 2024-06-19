#ifndef SENSORDATAGENERATOR_H
#define SENSORDATAGENERATOR_H

#include "plcdata.h"
#include "datasender.h"

class SensorDataGenerator : public PLCData, public dataSender {
public:
    SensorDataGenerator(QString portName, unsigned int Pressure, unsigned int Temperature);
    ~SensorDataGenerator() {}

    void SendData(const tuple<float, float> inputValues);
    tuple<float, float> getStatus();

private:
    static unsigned int activeStation;
    const  unsigned int ID;

};
#endif // SENSORDATAGENERATOR_H
