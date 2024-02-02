#ifndef PLCDATA_H
#define PLCDATA_H

#include <cmath>
#include <ctime>
#include <tuple>

//#define B 30
//#define C 60
#define LogPend 3000

using namespace std;

class PLCData {
public:
    PLCData(unsigned int Pressure, unsigned int Temperature);
    ~PLCData() {}

    static tuple<float, float> emulate(tuple<float, float> state, unsigned int time);

protected:
    tuple<float, float> _input;

private:
    static float logCurve(const float _value, unsigned int _time);
    static float linealCurve(const float _value);
};
#endif // PLCDATA_H
