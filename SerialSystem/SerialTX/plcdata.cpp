#include "plcdata.h"

PLCData::PLCData(unsigned int Pressure, unsigned int Temperature) {
    this->_input    = make_tuple(Pressure, Temperature);
    srand(time(NULL));
}

tuple<float, float> PLCData::emulate(tuple<float, float> state, unsigned int _time) {
    float pressure = PLCData::logCurve(get<0>(state), _time),
          temperature = PLCData::logCurve(get<1>(state), _time);

    if(pressure <= get<0>(state) || temperature <= get<1>(state))
        return make_tuple(pressure, temperature);

    return make_tuple(PLCData::linealCurve(get<0>(state)), PLCData::linealCurve(get<1>(state)));
}

float PLCData::logCurve(const float _value, unsigned int _time) {
    return (float)(_value * log10(_time)/log10(LogPend));
}

float PLCData::linealCurve(const float _value) {
    return _value + (float)(pow(-1, rand()%(3-1)+1) * (rand()%25)/100);
}
