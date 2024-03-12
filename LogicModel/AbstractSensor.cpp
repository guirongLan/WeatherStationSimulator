#include "AbstractSensor.h"

namespace Sensor {

AbstractSensor::AbstractSensor(const std::string& name,const unsigned int& ID,const Type& typeName)
    :name(name),ID(ID),typeName(typeName){}

const std::string& AbstractSensor::getName() const{
        return name;
    }

void AbstractSensor::setName(const std::string& newName){
        name = newName;
    }

const unsigned int& AbstractSensor::getID() const{
    return ID;
}

const Type& AbstractSensor::getTypeName() const{
    return typeName;
}

}
