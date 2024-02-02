#ifndef DATASENDER_H
#define DATASENDER_H

#include <QSerialPort>
#include <QBuffer>
#include <tuple>

using namespace std;

class dataSender {
public:
    dataSender(QString portName);
    ~dataSender();

protected:
    void sendByte(const QByteArray _Data);

private:
    QSerialPort m_serialPort;
};

#endif // DATASENDER_H
