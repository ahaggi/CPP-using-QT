#include <iostream>

#include "widget.h"
#include "ui_widget.h"
#include "colorchangerimpl.h"
#include "colorchangercolorblind.h"

spel_gui::spel_gui(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget),
    changer(new colorChangerImpl),
    manager(new colorManager)
{
    ui->setupUi(this);
    auto *button = new QPushButton("Click me!",this);

    auto *layout = new QVBoxLayout;

    layout->addWidget(button);

    connect(button, &QPushButton::clicked, this, &spel_gui::updateColor);

    //connect(button, &QPushButton::clicked,this,&Widget::updateColorHighCoupling);

    //connect(button, &QPushButton::clicked,this,&Widget::updateColorHighestCoupling);

    this->setLayout(layout);
}

spel_gui::~spel_gui()
{
    delete ui;
}

void spel_gui::updateColor()
{
    this->setStyleSheet(QString::fromStdString(changer->randomColor()));
}

void spel_gui::updateColorHighCoupling()
{
    auto color = manager->getRandomColor();

    this->setStyleSheet(QString::fromStdString(color));
}


void spel_gui::updateColorHighestCoupling()
{
   //auto color = manager->cChanger->randomColor();

   // this->setStyleSheet(QString::fromStdString(color));
}

