#include "spel_gui.h"

#include <QApplication>
#include <QSignalMapper>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    spel_gui gui;


    QObject::connect(gui.mapper , SIGNAL(mapped(int)) , &gui , SLOT(proev(int)) );
    QObject::connect(gui.mapper , SIGNAL(mapped(QString)) , &gui , SLOT(startPaaNytt()) );


    QObject::connect(gui.wd.ok , SIGNAL(clicked(bool)) , &gui , SLOT(startPaaNytt()));
    QObject::connect(gui.wd.ok,SIGNAL(clicked(bool)),&(gui.wd),SLOT(close()));


    gui.show();

    return a.exec();
}
