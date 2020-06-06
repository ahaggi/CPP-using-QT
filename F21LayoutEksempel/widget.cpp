#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    vbox = new QVBoxLayout();
    hbox1 = new QHBoxLayout();
    hbox2 = new QHBoxLayout();
    button1 = new QPushButton("Button 1", this);
    button2 = new QPushButton("Button 2", this);
    button3 = new QPushButton("Button 3", this);
    button4 = new QPushButton("Button 4", this);
    rbutton1 = new QRadioButton("Radio 1", this);
    rbutton2 = new QRadioButton("Radio 2", this);
    rbutton3 = new QRadioButton("Radio 3", this);
    rbutton4 = new QRadioButton("Radio 4", this);

    setWindowTitle("HBox og VBox Widget");

    this->setLayout(vbox);

    vbox->addLayout(hbox1);
    vbox->addSpacing(100);
    vbox->addLayout(hbox2);
    vbox->addStretch();

    hbox1->addWidget(button1);
    hbox1->addWidget(button2);
    hbox1->addWidget(button3);
    hbox1->addWidget(button4);

    hbox2->addWidget(rbutton1);
    hbox2->addWidget(rbutton2);
    hbox2->addWidget(rbutton3);
    hbox2->addWidget(rbutton4);

}

Widget::~Widget()
{

}
