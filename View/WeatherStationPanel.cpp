#include "WeatherStationPanel.h"
#include "WeatherStationWidget.h"
namespace View{
WeatherStationPanel::WeatherStationPanel(std::vector<Sensor::WeatherStation>& myWeatherStations,QWidget *parent)
    : QWidget{parent}{

    weatherStationsMainLayout = new QVBoxLayout(this);
    weatherStationsMainLayout->setAlignment(Qt::AlignLeft|Qt::AlignTop);
    //search textBox

    //create Panels inside QScrollArea
    //non scrivere QVBoxLayout this perche cosi fa contro/sovrapposizione la Main Lyout
    //questo layout serve a QScrollArea
    qScrollLayout = new QVBoxLayout();
    //a function that show All Widgets not setted
    showAllWidgets(myWeatherStations);

    scrollArea = new QScrollArea(this);
    scrollContainer = new QWidget;
    scrollContainer->setLayout(qScrollLayout);
    scrollArea->setWidget(scrollContainer);
    scrollArea->setMaximumHeight(500);
    scrollArea->setMaximumWidth(400);
    weatherStationsMainLayout->addWidget(scrollArea);
    QPushButton* createNewStation = new QPushButton("Create New Weather Station");
    weatherStationsMainLayout->addWidget(createNewStation);
    //connect
}
void WeatherStationPanel::showAllWidgets(std::vector<Sensor::WeatherStation>& myWeatherStations){
    WeatherStationWidget* p1;
    for(Sensor::WeatherStation i: myWeatherStations){
        p1 = new WeatherStationWidget(&i);
        qDebug() <<"my widgets memory address" << p1;
        weatherStationsPanels.push_back(p1);
        qScrollLayout->addWidget(p1);
        p1->showName();
        //connect(p1,&WeatherStationWidget::refreshWidget,this,&WeatherStationPanel::refreshPanel);
        //delete p1;
    }
}
void WeatherStationPanel::refreshPanel(){
    //delete qScrollLayout;
    //showAllWidgets();
    emit thereIsSomethingChanged();
}



}
