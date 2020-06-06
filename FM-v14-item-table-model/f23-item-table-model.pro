QT       = core gui
# QT += network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE = app
SOURCES += main.cpp \
    listmodel.cpp \
    tablemodel.cpp

HEADERS += \
    listmodel.h \
    tablemodel.h

