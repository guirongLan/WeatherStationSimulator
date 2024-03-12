#ifndef MODIFYWEATHERSTATIONDIALOG_H
#define MODIFYWEATHERSTATIONDIALOG_H


#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>

namespace View{


class ModifyWeatherStationDialog: public QDialog{
    Q_OBJECT
    private:
        //main layout
        QVBoxLayout* mainDialogLayout;
        //label & data layout
        QHBoxLayout* wStationNameLayout;
        //label & data
        QLabel* wStationNameLabel;
        QLineEdit* wStationNameText;
        //buttons layout
        QHBoxLayout* buttonsLayout;
        //buttons
        QPushButton* modifyButton;
        QPushButton* cancelButton;

    public:
        explicit ModifyWeatherStationDialog(const std::string& weatherStationName,QDialog *parent = nullptr);
    signals:
        void sendConfirmModifySignalToWidget(const std::string& newName);
    public slots:
        void confirmModifySlot();
        void updateText(const QString& text);
};

}
#endif // MODIFYWEATHERSTATIONDIALOG_H
