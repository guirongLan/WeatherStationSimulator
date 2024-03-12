#include "ModifyWeatherStationDialog.h"
#include <QString>
#include <string>
namespace View{

ModifyWeatherStationDialog::ModifyWeatherStationDialog(const std::string& weatherStationName,QDialog *parent):QDialog{parent}{
    setWindowTitle("Modify Weather Station Name");
    //main dialog layout
    mainDialogLayout = new QVBoxLayout(this);
    // weather station layout + label & Textbox
    wStationNameLayout = new QHBoxLayout();
    wStationNameLabel = new QLabel("WeatherStationName:", this);
    //pass name of Weather Station
    wStationNameText = new QLineEdit(QString::fromStdString(weatherStationName), this);
    connect(wStationNameText,&QLineEdit::textChanged,this,&ModifyWeatherStationDialog::updateText);
    wStationNameText->setFixedSize(150, 50);
    wStationNameLayout->addWidget(wStationNameLabel);
    wStationNameLayout->addWidget(wStationNameText);
    //2 buttons to decide create or discard
    buttonsLayout = new QHBoxLayout();
    modifyButton = new QPushButton("Modify",this);
    buttonsLayout->addWidget(modifyButton);
    //connect
    /*connect(modifyButton,&QPushButton::pressed, this,[=](){
        ciao(wStationNameText->text().toStdString());
        accept();

    });*/
    qDebug() << "before confirmmmm" << QString::fromStdString(wStationNameText->text().toStdString());
    //a strange bug this connect cant obtain text value chaged same time
    //connect(modifyButton,&QPushButton::pressed,std::bind(&ModifyWeatherStationDialog::confirmModifySlot,this,wStationNameText->text().toStdString()));
    connect(modifyButton,&QPushButton::pressed,this,&ModifyWeatherStationDialog::confirmModifySlot);
    cancelButton = new QPushButton("Cancel",this);
    buttonsLayout->addWidget(cancelButton);

    mainDialogLayout->addLayout(wStationNameLayout);
    mainDialogLayout->addLayout(buttonsLayout);
    setLayout(mainDialogLayout);
}
void ModifyWeatherStationDialog::updateText(const QString& newTexT){
    qDebug() << "Update" << newTexT;
    wStationNameText->setText(newTexT);
}
void ModifyWeatherStationDialog::confirmModifySlot(){
    qDebug() << "after confirmmmm" << QString::fromStdString(wStationNameText->text().toStdString());
    //qDebug() << "newNAme confirmmmm" << QString::fromStdString(newName);
    //emit
    emit sendConfirmModifySignalToWidget(wStationNameText->text().toStdString());
    accept();
}

}
