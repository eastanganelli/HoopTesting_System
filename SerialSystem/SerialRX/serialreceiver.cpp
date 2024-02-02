#include "serialreceiver.h"

void serialRX::readData() {
    this->m_serialPort->waitForReadyRead(-1);
    QByteArray data = this->m_serialPort->readLine();

#ifdef DEBUG_MODE
    qDebug() << "Data read: " << data;
#endif

    this->buffer.append(data);
}

QByteArray serialRX::getFullline() {
    int index = buffer.indexOf('\n');
    if (index == -1) {
        return QByteArray();
    }

    QByteArray line = buffer.mid(0, index);
    buffer.remove(0, index + 1);
    return line;
}
