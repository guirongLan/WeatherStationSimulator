#ifndef WEATHERSTATION_H
#define WEATHERSTATION_H
#include <string>
#include <vector>
#include "AbstractSensor.h"
namespace Sensor {

class WeatherStation{
    private:
        std::string weatherStationName;
        std::vector<Sensor::AbstractSensor*> mySensorContainer;

    public:
        WeatherStation(const std::string& weatherStationName);
        const std::string& getStationName() const ;
        void setStationName(const std::string& newName);//problem
};

}

#endif // WEATHERSTATION_H
