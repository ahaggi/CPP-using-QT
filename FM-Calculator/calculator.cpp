#include <QGridLayout>
#include <QSignalMapper>
#include "calculator.h"

noe::noe(){
    operand = memory = 0;
    opr = PLUS;
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
    connect(mapper, SIGNAL(mapped(int)), this, SLOT(keyPressed(int)));
    connect(mapper, SIGNAL(mapped(QString)), this, SLOT(keyPressed(QString)));
}

//      Number key presses are handled here
//      Updates the number in memory and on display
void noe::keyPressed(int i){
    operand = operand*10 + i;
    lineDisplay->setText(QString::number(operand));
}

//      Operator key presses are handled here
//      Calculates intermediate values and final result
void noe::keyPressed(QString str){
    memory += opr*operand;
    operand = 0;
    lineDisplay->clear();
    if(str == "+"){
        opr = PLUS;
    }
    else if( str == "-"){
        opr = MINUS;
    }
    else if( str == "="){
        lineDisplay->setText(QString::number(memory));
        operand = memory;
        memory = 0;
        opr = PLUS;
    }
    else {
        // The user pressed "C"
        memory = operand = 0;
        opr = PLUS;
    }
}
