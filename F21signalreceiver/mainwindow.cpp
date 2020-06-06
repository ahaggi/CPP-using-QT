#include <QApplication>
#include <QtWidgets>
#include "mainwindow.h"
#include "signalreceiver.h"

MainWindow::MainWindow(QWidget *parent) : QWidget(parent){

    QVBoxLayout *outerLayout = new QVBoxLayout(this);
    QGridLayout *mainLayout = new QGridLayout();
    knapp1 = new QPushButton("Ok");
    knapp2 = new QPushButton("Cancel");
    textInput1 = new QLineEdit();
    textInput2 = new QLineEdit();

    outerLayout->addLayout(mainLayout);
    mainLayout->addWidget(knapp1, 0, 0);
    mainLayout->addWidget(knapp2, 0, 1);
    outerLayout->addStretch();
    outerLayout->addWidget(textInput1);
    mainLayout->addWidget(textInput2, 1, 0, 1, 2);

    connect(knapp1, SIGNAL(clicked(bool)), this, SIGNAL(mySignal()));
    connect(knapp2, SIGNAL(clicked(bool)), this, SLOT(buttonSlot()));

/**
   Hvorfor må den delen stå utenfor denne cpp filen??
    Denne delen ligger i main.cpp, for knytte mySignal til printMessage,,,
    connect mySignal som ligger her til printmessage som ligger i en annen fil

    QObject::connect(this,  SIGNAL(mySignal()), &signalReceiver, SLOT(printMessage()));
*/



}

void MainWindow::buttonSlot()
{
    qDebug("Inside class MainWindow");
}
