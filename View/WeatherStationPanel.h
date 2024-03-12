#ifndef WEATHERSTATIONPANEL_H
#define WEATHERSTATIONPANEL_H

#include "View/WeatherStationWidget.h"

#include "LogicModel/WeatherStation.h"

#include <QWidget>
#include <QScrollArea>
#include <QVBoxLayout>
#include <QPushButton>
#include <vector>

namespace View{
class WeatherStationPanel : public QWidget
{
    Q_OBJECT
    private:
        QVBoxLayout* weatherStationsMainLayout;
        std::vector<WeatherStationWidget*> weatherStationsPanels;
        QVBoxLayout* qScrollLayout;
        QScrollArea* scrollArea;
        QWidget *scrollContainer;
        QPushButton* AddNewWeatherStationButton;

    public:
        explicit WeatherStationPanel(std::vector<Sensor::WeatherStation>& myWeatherStations,QWidget *parent = nullptr);
        void showAllWidgets(std::vector<Sensor::WeatherStation>& myWeatherStations);
    signals:
        void thereIsSomethingChanged();
    public slots:
        void refreshPanel();

};

}
#endif // WEATHERSTATIONPANEL_H
