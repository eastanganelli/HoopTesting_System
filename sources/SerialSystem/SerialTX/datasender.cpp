#include "datasender.h"

dataSender::dataSender(QString portName) {
    this->m_serialPort.setPortName(portName);
    this->m_serialPort.open(QIODevice::WriteOnly);
    this->m_serialPort.setBaudRate(QSerialPort::Baud9600);
    this->m_serialPort.setFlowControl(QSerialPort::NoFlowControl);
    this->m_serialPort.setDataBits(QSerialPort::Data8);
}

dataSender::~dataSender() {
    this->m_serialPort.close();
}

void dataSender::sendByte(const QByteArray _Data) {
    this->m_serialPort.flush();
    this->m_serialPort.write(_Data);
    this->m_serialPort.waitForBytesWritten(-1);
}
