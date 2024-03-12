#ifndef PYRANOMETER_H
#define PYRANOMETER_H
#include "AbstractSensor.h"

namespace Sensor{

    enum PyranoUnit {WATTS_PER_SQUARE_METER,KILOWATTS_PER_SQUARE_METER};

class Pyranometer:public AbstractSensor{
    private:
        PyranoUnit pyranoUnit;
        std::vector<unsigned int> dataPyranometer;
    public:
        Pyranometer(
                const std::string& name,
                const unsigned int& ID,
                const Type& typeName,
                const PyranoUnit& pyranoUnit,
                const std::vector<unsigned int>& dataPyranometer
                );
        virtual Pyranometer* clone() const;
        //getter & setter
        const PyranoUnit& getPyranoUnit() const;
        void setPyranoUnit(const PyranoUnit& newPyranoUnit);

        const std::vector<unsigned int>& getDataPyranometer() const;
        void setDataPyranometer(const int& i,const double& newDataPyranometer);
};
}
#endif // PYRANOMETER_H
