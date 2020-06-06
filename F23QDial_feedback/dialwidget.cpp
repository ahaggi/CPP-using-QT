#include <QDebug>
#include <QLabel>
#include "dialwidget.h"

DialWidget::DialWidget(QWidget *parent)
    : QWidget(parent)
{
    vbox = new QVBoxLayout(this);
    hbox = new QHBoxLayout();
    dial1 = new QDial();
    dial2 = new QDial();
    vbox->addWidget(new QLabel("Eksempel på sammenkobling av valueChanged signal og\n"
                               "setValue slot på QDial. QDial er implementert med en sjekk\n"
                               "for om verdien faktisk er endret før en sender ut valueChanged\n"
                               "signalet. Dette er viktig å huske når en definerer egne signals/slots,\n"
                               "for å unngå evige signalløkker i våre programmer.\n"));
    vbox->addLayout(hbox);

    dial1->setRange(0,99);
    dial1->setNotchTarget(10);
    dial1->setNotchesVisible(true);

    dial2->setRange(0,99);
    dial2->setNotchTarget(10);
    dial2->setNotchesVisible(true);

    hbox->addSpacing(25);
    hbox->addWidget(dial1);
    hbox->addStretch();
    hbox->addWidget(dial2);
    hbox->addSpacing(25);

    // Selv om valueChanged signalet er tilsynelatende koblet i en evig
    // løkke mellom dial1 og dial2 her, så vil en se at fra programmets
    // utskrift til konsollet at det ikke skjer allikevel, fordi valueChanged
    // signalet sendes bare ut når verdien faktisk endres, ikke hver gang
    // setValue kalles.
    connect(dial1, SIGNAL(valueChanged(int)), dial2, SLOT(setValue(int)));
    connect(dial2, SIGNAL(valueChanged(int)), dial1, SLOT(setValue(int)));
    connect(dial1, SIGNAL(valueChanged(int)), this, SLOT(printDial1Value(int)));
}

DialWidget::~DialWidget()
{

}

void DialWidget::printDial1Value(int value)
{
    qDebug() << "New dial1 value: " << value;
}
