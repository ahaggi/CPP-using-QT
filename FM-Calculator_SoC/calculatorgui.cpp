#include <QGridLayout>
#include <QSignalMapper>
#include "calculatorgui.h"


CalculatorGui::CalculatorGui(QWidget *parent) : QWidget(parent)
{
    calculator = new calculator();
    QGridLayout* mainLayout = new QGridLayout(this);

    //      Setting up the main display
    lineDisplay = new QLineEdit();
    lineDisplay->setAlignment(Qt::AlignRight);
    mainLayout->addWidget(lineDisplay,0, 0, 1, 4);
    QSignalMapper* mapper = new QSignalMapper();

    //      The number buttons are instantiated and
    //      mapped to integer values inside this loop
    for(int i = 0; i < 10; i++){
        buttons[i] = new QPushButton(QString::number(i));
        mapper->setMapping(buttons[i], i);
        connect(buttons[i], SIGNAL(clicked()), mapper, SLOT(map()));
        mainLayout->addWidget(buttons[i], 1+(9-i)/3,i > 0 ? (i-1)%3 : 1);
    }

    //      Instantiating and mapping the operator buttons
    btnPlus = new QPushButton("+");
    mapper->setMapping(btnPlus, "+");
    connect(btnPlus, SIGNAL(clicked()), mapper, SLOT(map()));
    mainLayout->addWidget(btnPlus, 2,3);

    btnMinus = new QPushButton("-");
    mapper->setMapping(btnMinus, "-");
    connect(btnMinus, SIGNAL(clicked()), mapper, SLOT(map()));
    mainLayout->addWidget(btnMinus, 3,3);

    btnEquals = new QPushButton("=");
    mapper->setMapping(btnEquals, "=");
    connect(btnEquals, SIGNAL(clicked()), mapper, SLOT(map()));
    mainLayout->addWidget(btnEquals, 4,3);

    btnClear = new QPushButton("C");
    mapper->setMapping(btnClear, "C");
    connect(btnClear, SIGNAL(clicked()), mapper, SLOT(map()));
    mainLayout->addWidget(btnClear, 1,3);

    //      Connecting the mapper to the slots
    connect(mapper, SIGNAL(mapped(int)), calculator, SLOT(keyPressed(int)));
    connect(mapper, SIGNAL(mapped(QString)), calculator, SLOT(keyPressed(QString)));
    connect(calculator, SIGNAL(valueChanged(int)), this, SLOT(changeValue(int)));
}


//      Slot for updating the display value
void CalculatorGui::changeValue(int val){
    lineDisplay->setText(QString::number(val));
}
