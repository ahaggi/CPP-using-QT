#include "signalreceiver.h"

SignalReceiver::SignalReceiver(QObject *parent) : QObject(parent)
{

}

int SignalReceiver::printMessage()
{
    qDebug("Ferdig!");
}
