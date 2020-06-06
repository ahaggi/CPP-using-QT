QT       = core gui
NETWORK_QT += network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE = app
SOURCES += main.cpp \
    mainwindow.cpp \
    signalreceiver.cpp

HEADERS += \
    mainwindow.h \
    signalreceiver.h
