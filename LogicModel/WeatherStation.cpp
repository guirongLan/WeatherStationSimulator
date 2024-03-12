#include "WeatherStation.h"
#include <QDebug>
#include <QString>
namespace Sensor {
WeatherStation::WeatherStation(const std::string& weatherStationName):weatherStationName(weatherStationName){
    qDebug() << "create" << QString::fromStdString(weatherStationName);
}

const std::string& WeatherStation::getStationName() const {
    qDebug() << "get" << QString::fromStdString(weatherStationName);
    return weatherStationName;
}

void WeatherStation::setStationName(const std::string& newName){
    qDebug() << "before setname" <<QString::fromStdString(newName);
    weatherStationName = newName;
    qDebug() << "after set name" <<QString::fromStdString(weatherStationName);
}

}
