#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <vector>
#include "View/ContentWidget.h"

#include "LogicModel/WeatherStation.h"


namespace View{

class MainWindow : public QMainWindow
{
    Q_OBJECT
    private:
        QWidget* mainWidget;
        View::ContentWidget* contentWidget;
        QVBoxLayout* mainLayout;
        //tiene tracci di tutti dati
        std::vector<Sensor::WeatherStation>& myWeatherStations;

    public:
        MainWindow(std::vector<Sensor::WeatherStation>& myWeatherStations,QWidget *parent = nullptr);
        ~MainWindow();

};


}
#endif // MAINWINDOW_H
