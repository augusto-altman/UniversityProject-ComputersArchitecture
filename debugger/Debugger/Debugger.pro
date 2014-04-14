#-------------------------------------------------
#
# Project created by QtCreator 2014-04-13T12:55:41
#
#-------------------------------------------------


include(3rdparty/qextserialport/src/qextserialport.pri)
QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Debugger
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui
