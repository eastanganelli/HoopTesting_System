#include <QCoreApplication>
#include <QSerialPort>
#include <QByteArray>
#include <QDebug>
#include "serialreceiver.h"

int main() {
    QSerialPort serialPort;

    serialPort.setPortName("COM30");
    serialPort.setBaudRate(QSerialPort::Baud9600);
    serialPort.setParity(QSerialPort::NoParity);
    serialPort.setStopBits(QSerialPort::OneStop);

    serialRX Lectura(&serialPort);
    QString indata;

    qDebug() << "Abriendo Puerto de lectura" << Qt::endl << "Esperando mensajes" << Qt::endl;
    while(true) {
        Lectura.readData();

        QByteArray line = Lectura.getFullline();
        if (!line.isEmpty()) {
            qDebug() << "Received line: " << line;
        }
    }

    return 0;
}

/*
class SerialBuffer {
public:
    SerialBuffer(QSerialPort *serialPort) : serialPort(serialPort) {}

    void read() {
        QByteArray data = serialPort->readAll();
        buffer.append(data);
    }

    QByteArray getFullLine() {
        int index = buffer.indexOf('\n');
        if (index == -1) {
            return QByteArray();
        } else {
            QByteArray line = buffer.mid(0, index);
            buffer.remove(0, index + 1);
            return line;
        }
    }

private:
    QSerialPort *serialPort;
    QByteArray buffer;
};

int main() {
    QSerialPort serialPort("COM30");
    serialPort.setBaudRate(QSerialPort::Baud9600);
    serialPort.setDataBits(QSerialPort::Data8);
    serialPort.setParity(QSerialPort::NoParity);
    serialPort.setStopBits(QSerialPort::OneStop);

    SerialBuffer buffer(&serialPort);
    serialPort.open(QIODevice::ReadOnly);

    while (true) {
        serialPort.waitForReadyRead(-1);
        buffer.read();

        QByteArray line = buffer.getFullLine();
        if (!line.isEmpty()) {
            qDebug() << "Received line: " << line;
        }
    }

    return 0;
}
*/
