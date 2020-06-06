#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets>
#include "signalreceiver.h"

class MainWindow : public QWidget
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
     SignalReceiver signalReceiver ;

signals:
    void mySignal();

public slots:
    void buttonSlot();

private:
    QPushButton *knapp1, *knapp2;
    QLineEdit *textInput1, *textInput2;
};

#endif // MAINWINDOW_H
