#ifndef THERMOMETER_H
#define THERMOMETER_H

#include "AbstractSensor.h"
namespace Sensor{

    enum ThermoUnit{CELSIUS,FAHRENHEIT,KELVIN};

class Thermometer:public AbstractSensor {
    private:
        ThermoUnit thermoUnit;//di default CELSIUS
        std::vector<double> dataThermometer;
        double minTemperature;//il raggio minimo di un thermometer//campi facoltativi
        double maxTemperature;//massimo
    public:
        Thermometer(
                const std::string& name,
                const unsigned int& ID,
                const Type& typeName,
                const ThermoUnit& thermoUnit,//di default CELSIUS
                const std::vector<double>& dataThermometer,
                const double& minTemperature,//il raggio minimo di un thermometer//campi facoltativi
                const double& maxTemperature//massimo
                );
        virtual Thermometer* clone() const;

        //getter & setter
        const ThermoUnit& getThermoUnit() const;
        void setThermoUnit(const ThermoUnit& newThermoUnit);

        const std::vector<double>& getDataThermometer() const;
        void setDataThermometer(const int& i,const double& newDataThermometer);

        const double& getMinTemperature() const;
        void setMinTemperature(const double& newMinTemperature);

        const double& getMaxTemperature() const;
        void setMaxTemperature(const double& newMaxTemperature);
};


}
#endif // THERMOMETER_H
