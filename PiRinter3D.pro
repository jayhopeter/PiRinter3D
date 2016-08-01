#-------------------------------------------------
#
# Project created by QtCreator 2016-07-25T12:11:50
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PiRinter3D
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    coildialog.cpp \
    steppermotor.cpp \
    stepperdriver.cpp \
    motorconfigdialog.cpp \
    gcodeinterpreter.cpp \
    motorcontroller.cpp

HEADERS  += mainwindow.h \
    coildialog.h \
    motorworker.h \
    steppermotor.h \
    stepperdriver.h \
    motorconfigdialog.h \
    gcodeinterpreter.h \
    motorcontroller.h

FORMS    += mainwindow.ui \
    coildialog.ui \
    stepperdriver.ui \
    motorconfigdialog.ui

LIBS += -L/usr/local/include -lwiringPi

RESOURCES += \
    StepperDriverRsc.qrc \
    PiRinter.qrc
