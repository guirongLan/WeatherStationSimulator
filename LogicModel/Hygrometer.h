#ifndef HYGROMETER_H
#define HYGROMETER_H

#include "Barometer.h"
#include "Thermometer.h"
namespace Sensor{

    enum HygroUnit{PERCENTAGE,GRAMS_PER_CUBIC_METER};

class Hygrometer:public AbstractSensor{
    private:
        Barometer baro;
        Thermometer thermo;
        HygroUnit hygroUnit;
        std::vector<unsigned int> dataHygrometerRelative;
        std::vector<double> dataHygrometerAbsolute;
        //il raggio dipende da barometer e thermometer
    public:
        Hygrometer(
                const std::string& name,
                const unsigned int& ID,
                const Type& typeName,
                const Barometer& baro,//evitare la costruzione di copia poi
                const Thermometer& thermo,
                const HygroUnit& hygroUnit,
                const std::vector<unsigned int>& dataHygrometerRelative,
                const std::vector<double>& dataHygrometerAbsolute
                );
        virtual Hygrometer* clone() const;

        const Barometer& getBarometer() const;
        void setBarometer(const int& i,const unsigned int& newDataBarometer);

        const Thermometer& getThermometer() const;
        void setThermometer(const int& i,const double& newDataThermometer);

        const HygroUnit& getHygroUnit() const;
        void setHygroUnit(const HygroUnit& newHygroUnit);

        const std::vector<unsigned int>& getDataRelative() const;
        void setDataRelative(const int& i,const unsigned int& newDataRelative);

        const std::vector<double>& getDataAbsolute() const;
        void setDataAbsolute(const int& i,const double& newDataAbsolute);

};

}

#endif // HYGROMETER_H
