#include <QDebug>
#include <QThread>
#include "sensordatagenerator.h"

#define ms 250

int main() {
    unsigned int i = 1;
    SensorDataGenerator SensorI("COM28", 10, 27);


    qDebug() << "Sending Data to COM 28" << Qt::endl;
    while(true) {
        tuple<float, float> _output = SensorDataGenerator::emulate(SensorI.getStatus(), i);
        SensorI.SendData(_output);
        i++;

        (void)_sleep(ms);
        qDebug() << "New data generated";
    }

    return 0;
}
