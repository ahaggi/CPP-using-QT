#-------------------------------------------------
#
# Project created by QtCreator 2016-04-19T13:34:30
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = couplingExample
TEMPLATE = app

CONFIG += c++11

SOURCES += main.cpp\
        widget.cpp \
    colorchanger.cpp \
    colorchangerimpl.cpp \
    colorchangercolorblind.cpp \
    colormanager.cpp

HEADERS  += widget.h \
    colorchanger.h \
    colorchangeradt.h \
    colorchangerimpl.h \
    colorchangercolorblind.h \
    colormanager.h

FORMS    += widget.ui
