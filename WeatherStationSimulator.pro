QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    LogicModel/AbstractSensor.cpp \
    LogicModel/Barometer.cpp \
    LogicModel/Hygrometer.cpp \
    LogicModel/Pyranometer.cpp \
    LogicModel/Thermometer.cpp \
    LogicModel/WeatherStation.cpp \
    View/ContentWidget.cpp \
    View/ModifyWeatherStationDialog.cpp \
    View/MainWindow.cpp\
    View/WeatherStationPanel.cpp \
    View/WeatherStationWidget.cpp \
    main.cpp


HEADERS += \
    LogicModel/AbstractSensor.h \
    LogicModel/Barometer.h \
    LogicModel/Hygrometer.h \
    LogicModel/Pyranometer.h \
    LogicModel/Thermometer.h \
    LogicModel/WeatherStation.h \
    View/ContentWidget.h \
    View/ModifyWeatherStationDialog.h \
    View/MainWindow.h \
    View/WeatherStationPanel.h \
    View/WeatherStationWidget.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
