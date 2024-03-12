#ifndef WEATHERSTATIONWIDGET_H
#define WEATHERSTATIONWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QString>
#include "LogicModel/WeatherStation.h"
#include "ModifyWeatherStationDialog.h"

namespace View{

class WeatherStationWidget:public QWidget{
    Q_OBJECT
    private:
        QLabel* weatherStationName;
        View::ModifyWeatherStationDialog* p1;
    public:
        Sensor::WeatherStation* weatherStation;
        explicit WeatherStationWidget(Sensor::WeatherStation* weatherStation,QWidget *parent = nullptr);
        void showName();

    signals:
        void refreshWidget();

    public slots:
        void prepareModify(const std::string&);
        void confirmModifySlot(Sensor::WeatherStation& weatherStation,const std::string&);
};

}

#endif // WEATHERSTATIONWIDGET_H
