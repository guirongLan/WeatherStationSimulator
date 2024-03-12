#ifndef ABSTRACTSENSOR_H
#define ABSTRACTSENSOR_H

#include <string>
#include <vector>

namespace Sensor{

    enum Type{THERMOMETER,HYGROMETER,anemometer,BAROMETER,PYRANOMETER};

class AbstractSensor{
    private:
        std::string name;//string è un oggetto
        const unsigned int ID;
        const Type typeName;
    public:
        AbstractSensor(
            const std::string& name,
            const unsigned int& ID,
            const Type& typeName
        );
    virtual ~AbstractSensor() = default;
    //marcare una funzione costante significa che non faccio modifiche oggetto di invocazione e basta e non dell'oggetto ritornato
    virtual AbstractSensor* clone() const = 0;//rendere la classe astratta
    // virtual void changeUnit(std::string newUnit);

    //getter//setter
    const std::string& getName() const;//siccome string è oggetto allora riotrno per valore si effettua una copia quindi faccio ritornare come riferimento,ma siccome la funzione è marcata costante devo ritornare un riferimento costante
    void setName(const std::string& newName);
    const unsigned int& getID() const;// variabile è gia costante
    const Type& getTypeName() const;//ritorno per riferimento per evitare la chiamata di costruttore di copia

};
}

#endif // ABSTRACTSENSOR_H
