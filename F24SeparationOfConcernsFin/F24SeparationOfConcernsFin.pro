TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    player.cpp \
    diceroller.cpp \
    gamemenu.cpp \
    gamemanager.cpp

HEADERS += \
    player.h \
    diceroller.h \
    gamemenu.h \
    gametype.h \
    gamemanager.h
