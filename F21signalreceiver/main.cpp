#include <QApplication>
#include <QtWidgets>
#include "mainwindow.h"
#include "signalreceiver.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow window;

    SignalReceiver signalReceiver;
    QObject::connect(&window, SIGNAL(mySignal()), &signalReceiver, SLOT(printMessage()));

    window.show();

    return app.exec();
}
