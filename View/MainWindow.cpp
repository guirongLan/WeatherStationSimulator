#include "mainwindow.h"
#include <QVBoxLayout>
#include <QPushButton>
namespace View{
//ogni QWidget ha bisogno di un layout
MainWindow::MainWindow(std::vector<Sensor::WeatherStation*>& myWeatherStations,QWidget *parent)
    :QMainWindow(parent), myWeatherStations(myWeatherStations)
{
    setWindowTitle("Weather Station Simulator");
    //set content widget
    contentWidget = new ContentWidget(myWeatherStations);
    setCentralWidget(contentWidget);

    //connect(contentWidget,&ContentWidget::updatePanelAfterChanges,this,&MainWindow::update);
}

MainWindow::~MainWindow(){}

}
