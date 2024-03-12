#include "Barometer.h"
namespace Sensor {
Barometer::Barometer(const std::string& name,const unsigned int& ID,const Type& typeName,const double& altitude,
                     const BaroUnit& baroUnit,const std::vector<unsigned int>& dataBarometer,
                     const double& minPressure,const double& maxPressure)
    :AbstractSensor(name,ID,typeName), altitude(altitude),baroUnit(baroUnit),dataBarometer(dataBarometer),minPressure(minPressure),maxPressure(maxPressure) {}
//per momento lascio stare clone non so che cosa mi serve poi

Barometer* Barometer::clone() const{
    return new Barometer(*this);//costruzione di copia da ridefinire?
}

const double& Barometer::getAltitude() const{
    return altitude;
}
void Barometer::setAltitude(const double& newAltitude){
    altitude = newAltitude;
}

const BaroUnit& Barometer::getBaroUnit()const{
    return baroUnit;
}
void Barometer::setBaroUnit(const BaroUnit& newBaroUnit){
    baroUnit = newBaroUnit;
}

const std::vector<unsigned int>& Barometer::getDataBarometer() const{
    return dataBarometer;
}
void Barometer::setDataBarometer(const int& i,const unsigned int& newDataBarometer){
    dataBarometer[i] = newDataBarometer;
}

const double& Barometer::getMinPressure() const{
    return minPressure;
}
void Barometer::setMinPressure(const double& newMinPressure){
    minPressure = newMinPressure;
}

const double& Barometer::getMaxPressure() const{
    return maxPressure;
}
void Barometer::setMaxPressure(const double& newMaxPressure){
    maxPressure = newMaxPressure;
}

}
