#include "ContentWidget.h"
namespace View{
ContentWidget::ContentWidget(std::vector<Sensor::WeatherStation>& myWeatherStations,QWidget *parent)
: QWidget{parent},myWeatherStations(myWeatherStations)
{
    contentLayout = new QHBoxLayout(this);
    contentLayout->setAlignment(Qt::AlignLeft|Qt::AlignTop);
    //create weatherStation Panel
    weatherStationPanel = new WeatherStationPanel(myWeatherStations);
    contentLayout->addWidget(weatherStationPanel);
    //connect(weatherStationPanel,&WeatherStationPanel::thereIsSomethingChanged,this,&ContentWidget::update);
}

void ContentWidget::update(){
    delete weatherStationPanel;
    //think want else is need to be deleted, stay care of garbage
    weatherStationPanel = new WeatherStationPanel(myWeatherStations);
    contentLayout->addWidget(weatherStationPanel);
    //connect(weatherStationWidget,&WeatherStationWidget::modifySignal,this,&ContentWidget::modifyWeatherStationName);

}

}
