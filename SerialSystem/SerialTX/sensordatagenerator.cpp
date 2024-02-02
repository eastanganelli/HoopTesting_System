#include "sensordatagenerator.h"

unsigned int SensorDataGenerator::activeStation = 0;

SensorDataGenerator::SensorDataGenerator(QString portName, unsigned int Pressure, unsigned int Temperature) : ID(++activeStation), dataSender(portName), PLCData(Pressure, Temperature) {

}

void SensorDataGenerator::SendData(const tuple<float, float> inputValues) {
    QString _Data;
    _Data = QString::number(ID) + "," + QString::number(get<0>(inputValues)) + "," + QString::number(get<1>(inputValues)) + "\n";
    this->sendByte(QByteArray(_Data.toStdString().c_str()));
}

tuple<float, float> SensorDataGenerator::getStatus() {
    return this->_input;
}
