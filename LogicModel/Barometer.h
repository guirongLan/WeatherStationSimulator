#ifndef BAROMETER_H
#define BAROMETER_H
#include "AbstractSensor.h"
namespace Sensor {

    enum BaroUnit {PASCALS,INCHES_OF_MERCURY,MILLIBARS};

class Barometer: public AbstractSensor{
    private:
        double altitude;
        BaroUnit baroUnit;
        std::vector<unsigned int> dataBarometer;//i dati lascio creare con altri funzioni
        double minPressure;
        double maxPressure;
    public:
        Barometer(
                const std::string& name,
                const unsigned int& ID,
                const Type& typeName,
                const double& altitude,
                const BaroUnit& baroUnit,
                const std::vector<unsigned int>& dataBarometer,
                const double& minPressure,
                const double& maxPressure
                );
        virtual Barometer* clone() const;
        //getter &setter
        const double& getAltitude() const;
        void setAltitude(const double& newAltitude);

        const BaroUnit& getBaroUnit() const;
        void setBaroUnit(const BaroUnit& newBaroUnit);

        const std::vector<unsigned int>& getDataBarometer() const;
        void setDataBarometer(const int& i,const unsigned int& newDataBarometer);

        const double& getMinPressure() const;
        void setMinPressure(const double& newMinPressure);

        const double& getMaxPressure() const;
        void setMaxPressure(const double& newMaxPressure);
};
} // namespace sensor
#endif // BAROMETER_H
