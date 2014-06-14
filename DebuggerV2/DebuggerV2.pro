#-------------------------------------------------
#
# Project created by QtCreator 2014-04-24T19:10:26
#
#-------------------------------------------------

include(3rdparty/qextserialport/src/qextserialport.pri)
QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DebuggerV2
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    signalmanagement.cpp \
    continueexethread.cpp

HEADERS  += mainwindow.h \
    signalmanagement.h \
    continueexethread.h

FORMS    += mainwindow.ui
