#include <QApplication>
#include <vector>
#include "LogicModel/WeatherStation.h"
#include "View/mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //meglio creare i dati dentro main

    std::vector<Sensor::WeatherStation*> myWeatherStations;
    Sensor::WeatherStation obj1("obj1");
    Sensor::WeatherStation obj2("obj2");
    Sensor::WeatherStation obj3("obj3");

    myWeatherStations.push_back(&obj1);
    myWeatherStations.push_back(&obj2);
    myWeatherStations.push_back(&obj3);

    View::MainWindow w(myWeatherStations);
    w.resize(1024,576);
    w.show();
    return a.exec();
}
