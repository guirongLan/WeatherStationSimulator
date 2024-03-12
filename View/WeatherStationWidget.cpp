#include "WeatherStationWidget.h"
#include <QHBoxLayout>
#include <QString>
#include <QPushButton>
#include <qinputdialog.h>
#include <functional>
namespace View {
    WeatherStationWidget::WeatherStationWidget(Sensor::WeatherStation* weatherStation,QWidget *parent)
        :QWidget{parent},weatherStation(weatherStation){
        QHBoxLayout* layout = new QHBoxLayout(this);
        layout->setAlignment(Qt::AlignLeft|Qt::AlignTop);
        weatherStationName = new QLabel();//da cambiare sicuramente poi
        layout->addWidget(weatherStationName);
        //create modify Button for modify
        QPushButton* prepareModifyButton = new QPushButton("modify",this);
        layout->addWidget(prepareModifyButton);
        qDebug() <<"WeatherStationWidget memory address" << this;
        qDebug() << "before connect" << QString::fromStdString(weatherStation->getStationName());
        //1^ way do pass param to another function
        /*connect(prepareModifyButton,&QPushButton::pressed,this,[=](){
            prepareModify(weatherStation.getStationName());
        });*/
        //2^ way to pass it
        //when user click button thats mean he want change something so i need prepare & show modify dialog

        connect(prepareModifyButton,&QPushButton::pressed,std::bind(&WeatherStationWidget::prepareModify,this,weatherStation->getStationName()));
    }
    void WeatherStationWidget::showName(){
        weatherStationName->setText(QString::fromStdString(weatherStation->getStationName()));
    }

    void WeatherStationWidget::prepareModify(const std::string& weatherStationName){
        qDebug() << "after connect" << QString::fromStdString(weatherStationName);
        qDebug() <<"prepareModify" << this;
        p1 = new ModifyWeatherStationDialog(weatherStationName);
       /* p1 = new ModifyWeatherStationDialog(weatherStationName, [](std::string str){
            qDebug() <<"callback" <<QString::fromStdString(str);
        });*/
        //bisogna connetere prima che venga eseguita

        //qDebug() <<"this before prepare" << &this->weatherStation;
        connect(p1,&ModifyWeatherStationDialog::sendConfirmModifySignalToWidget,this,[=](const std::string& newName){
            qDebug() <<"during connect" << &this->weatherStation;
            this->confirmModifySlot(*weatherStation,newName);//problem is here because he can't capture weatherStation
        });
        //connect(p1,&ModifyWeatherStationDialog::sendConfirmModifySignalToWidget,this,&WeatherStationWidget::confirmModifySlot);
        p1->exec();

        /*
        //farei una classe dialog cosi il codice sia piu mantenibile
        QInputDialog dialog;
        QString nome = dialog.getText(this, tr("modify Weather Station Name"),tr("New Name:"), QLineEdit::Normal);
        //std::string conversion=nome.toStdString();*/

    }
    void WeatherStationWidget::confirmModifySlot(Sensor::WeatherStation& weatherStation,const std::string& newName){
        qDebug() <<"this->WeatherStationWidget " << this;
        qDebug() <<"WeatherStationWidget" << &weatherStation;
        qDebug() << " Modify slot" <<QString::fromStdString(newName);
        qDebug() << " get name slot" <<QString::fromStdString(this->weatherStation->getStationName());
        //this->weatherStation.setStationName(newName);// problem in setStationName does not recognaze weatherStation
        //now weatherStation has been changed
    }
}
