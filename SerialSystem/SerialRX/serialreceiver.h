#ifndef SERIALRECEIVER_H
#define SERIALRECEIVER_H

#include <QSerialPort>
#include <QDebug>
//#define DEBUG_MODE 1

class serialRX {
public:
    serialRX(QSerialPort* serialPort) : m_serialPort(serialPort) {
        this->m_serialPort->open(QIODevice::ReadOnly);
    }
    ~serialRX() {}

    void readData();
    QByteArray getFullline();
private:
    QByteArray buffer;
    QSerialPort* m_serialPort;
};

#endif // SERIALRECEIVER_H
