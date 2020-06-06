QT       = core gui
%NETWORK%QT += network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE = app
SOURCES += main.cpp \
    calculator.cpp

HEADERS += \
    calculator.h
