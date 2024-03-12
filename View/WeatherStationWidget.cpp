#include "WeatherStationWidget.h"
#include <QHBoxLayout>
#include <QString>
#include <QPushButton>
#include <qinputdialog.h>
#include <functional>
namespace View {
    void WeatherStationWidget::showName(){
        weatherStationName->setText(QString::fromStdString(weatherStation->getStationName()));
    }

    WeatherStationWidget::WeatherStationWidget(Sensor::WeatherStation* weatherStation,QWidget *parent)
        :QWidget{parent},weatherStation(weatherStation){
        QHBoxLayout* layout = new QHBoxLayout(this);
        layout->setAlignment(Qt::AlignLeft|Qt::AlignTop);
        weatherStationName = new QLabel();//da cambiare sicuramente poi
        layout->addWidget(weatherStationName);
        //create modify Button for modify
        QPushButton* prepareModifyButton = new QPushButton("modify",this);
        layout->addWidget(prepareModifyButton);

        connect(prepareModifyButton,&QPushButton::pressed,std::bind(&WeatherStationWidget::prepareModify,this,weatherStation->getStationName()));
    }

    void WeatherStationWidget::prepareModify(const std::string& weatherStationName){

        ModifyWeatherStationDialog *dialog = new ModifyWeatherStationDialog(weatherStationName);
        connect(dialog,&ModifyWeatherStationDialog::sendConfirmModifySignalToWidget,this,[=](const std::string& newName){
            this->confirmModifySlot(*weatherStation, newName);
        });
        dialog->exec();
    }
    void WeatherStationWidget::confirmModifySlot(Sensor::WeatherStation& weatherStation,const std::string& newName){

        weatherStation.setStationName(newName);
        //now weatherStation has been changed
    }
}
