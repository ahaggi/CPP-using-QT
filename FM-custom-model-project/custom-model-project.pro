QT       = core gui
# QT += network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE = app
SOURCES += \
    Main.cpp \
    custommodel.cpp \
    itemclass.cpp \
    customtablemodel.cpp \
    customdelegate.cpp \
    editor.cpp

HEADERS += \
    custommodel.h \
    itemclass.h \
    customtablemodel.h \
    customdelegate.h \
    editor.h
