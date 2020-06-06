#include "widget_grid.h"

Widget_grid::Widget_grid(QWidget *parent)
    : QWidget(parent)
{
    grid_layout = new QGridLayout(this);
    button1 = new QPushButton("Button 1", this);
    button2 = new QPushButton("Button 2", this);
    button3 = new QPushButton("Button 3", this);
    button4 = new QPushButton("Button 4", this);
    rbutton1 = new QRadioButton("Button 1", this);
    rbutton2 = new QRadioButton("Button 2", this);
    rbutton3 = new QRadioButton("Button 3", this);
    rbutton4 = new QRadioButton("Button 4", this);

    setWindowTitle("Grid layout Widget");

    grid_layout->addWidget(button1, 0, 0);
    grid_layout->addWidget(button2, 0, 1);
    grid_layout->addWidget(button3, 0, 2);
    grid_layout->addWidget(button4, 0, 4);

    grid_layout->addWidget(rbutton1, 1, 0);
    grid_layout->addWidget(rbutton2, 1, 1);
    grid_layout->addWidget(rbutton3, 1, 2);
    grid_layout->addWidget(rbutton4, 1, 3);

}

Widget_grid::~Widget_grid()
{

}
