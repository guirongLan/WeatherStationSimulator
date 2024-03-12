    #include "Pyranometer.h"
namespace Sensor {
Pyranometer::Pyranometer(const std::string& name,const unsigned int& ID,const Type& typeName,
        const PyranoUnit& pyranoUnit,const std::vector<unsigned int>& dataPyranometer
                         ):AbstractSensor(name,ID,typeName),pyranoUnit(pyranoUnit),dataPyranometer(dataPyranometer){}

Pyranometer* Pyranometer::clone() const{
    return new Pyranometer(*this);
}

//getter & setter
const PyranoUnit& Pyranometer::getPyranoUnit() const{
    return pyranoUnit;
}
void Pyranometer::setPyranoUnit(const PyranoUnit& newPyranoUnit){
    pyranoUnit = newPyranoUnit;
}

const std::vector<unsigned int>& Pyranometer::getDataPyranometer() const{
    return dataPyranometer;
}
void Pyranometer::setDataPyranometer(const int& i,const double& newDataPyranometer){
    dataPyranometer[i] = newDataPyranometer;
}

}
