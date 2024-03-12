#ifndef CONTENTWIDGET_H
#define CONTENTWIDGET_H

#include <QWidget>
#include <vector>
#include <QHBoxLayout>
#include "LogicModel/WeatherStation.h"
#include "View/WeatherStationPanel.h"
//#include "View/ModifyWeatherStationDialog.h"

namespace View{

class ContentWidget : public QWidget
{
    Q_OBJECT
    private:
        QHBoxLayout* contentLayout;
        //non devo cancellare è giusto salvare di copia per lavorare poi
        std::vector<Sensor::WeatherStation>& myWeatherStations;
        View::WeatherStationPanel* weatherStationPanel;
    public:
        explicit ContentWidget(std::vector<Sensor::WeatherStation>& myWeatherStations,QWidget *parent = nullptr);
        void update();

};

}
#endif // CONTENTWIDGET_H
