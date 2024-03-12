#include "Thermometer.h"
namespace Sensor {

Thermometer::Thermometer(const std::string& name,const unsigned int& ID,const Type& typeName,const ThermoUnit& thermoUnit,const std::vector<double>& dataThermometer,
                         const double& minTemperature,const double& maxTemperature)
    :AbstractSensor(name,ID,typeName),thermoUnit(thermoUnit),dataThermometer(dataThermometer),minTemperature(minTemperature),maxTemperature(maxTemperature){}

Thermometer* Thermometer::clone() const{
    return new Thermometer(*this);
}

//getter & setter
const ThermoUnit& Thermometer::getThermoUnit() const{
    return thermoUnit;
}
void Thermometer::setThermoUnit(const ThermoUnit& newThermoUnit){
    thermoUnit = newThermoUnit;
}

const std::vector<double>& Thermometer::getDataThermometer() const{
    return dataThermometer;
}
void Thermometer::setDataThermometer(const int& i,const double& newDataThermometer){
    dataThermometer[i] = newDataThermometer;
}

const double& Thermometer::getMinTemperature() const{
    return minTemperature;
}
void Thermometer::setMinTemperature(const double& newMinTemperature){
    minTemperature = newMinTemperature;
}

const double& Thermometer::getMaxTemperature() const{
    return maxTemperature;
}

void Thermometer::setMaxTemperature(const double& newMaxTemperature){
    maxTemperature = newMaxTemperature;
}


}
