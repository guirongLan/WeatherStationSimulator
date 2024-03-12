#include "Hygrometer.h"
namespace Sensor{
Hygrometer::Hygrometer(const std::string& name,const unsigned int& ID,const Type& typeName,const Barometer& baro,
        const Thermometer& thermo,const HygroUnit& hygroUnit,const std::vector<unsigned int>& dataHygrometerRelative,const std::vector<double>& dataHygrometerAbsolute)
    :AbstractSensor(name,ID,typeName), baro(baro),thermo(thermo),hygroUnit(hygroUnit),dataHygrometerRelative(dataHygrometerRelative),dataHygrometerAbsolute(dataHygrometerAbsolute) {}

Hygrometer* Hygrometer::clone() const{
    return new Hygrometer(*this);
}

const Barometer& Hygrometer::getBarometer()const{
    return baro;
}
void Hygrometer::setBarometer(const int& i,const unsigned int& newDataBarometer){
    baro.setDataBarometer(i,newDataBarometer);
}

const Thermometer& Hygrometer::getThermometer()const{
    return thermo;
}
void Hygrometer::setThermometer(const int& i,const double& newDataThermometer){
    thermo.setDataThermometer(i,newDataThermometer);
}

const HygroUnit& Hygrometer::getHygroUnit() const{
    return hygroUnit;
}
void Hygrometer::setHygroUnit(const HygroUnit& newHygroUnit){
    hygroUnit = newHygroUnit;
}

const std::vector<unsigned int>& Hygrometer::getDataRelative() const{
    return dataHygrometerRelative;
}
void Hygrometer::setDataRelative(const int& i,const unsigned int& newDataRelative){
    dataHygrometerRelative[i] = newDataRelative;
}

const std::vector<double>& Hygrometer::getDataAbsolute() const{
    return dataHygrometerAbsolute;
}
void Hygrometer::setDataAbsolute(const int& i,const double& newDataAbsolute){
    dataHygrometerAbsolute[i] = newDataAbsolute;
}

}
