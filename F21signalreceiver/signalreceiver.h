#ifndef SIGNALRECEIVER_H
#define SIGNALRECEIVER_H

#include <QObject>

class SignalReceiver : public QObject
{
    Q_OBJECT
public:
    explicit SignalReceiver(QObject *parent = 0);

signals:

public slots:
    int printMessage();
};

#endif // SIGNALRECEIVER_H
