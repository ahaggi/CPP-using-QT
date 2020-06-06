
#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    offsetLabel = new QLabel("Offset");
    inputLabel = new QLabel("Input text");
    encLabel = new QLabel("Encrypted text");

    offsetTxt = new QSpinBox;
    inputTxt = new QLineEdit;
    encTxt = new QLineEdit;

    mainLayout = new QVBoxLayout(this);
    midLayout = new QHBoxLayout();
    labelLayout = new QVBoxLayout();
    lineEditLayout = new QVBoxLayout();

    encButon =  new QPushButton("Encrypt");

    labelLayout->addWidget(offsetLabel);
    labelLayout->addWidget(inputLabel);
    labelLayout->addWidget(encLabel);

    lineEditLayout->addWidget(offsetTxt);
    lineEditLayout->addWidget(inputTxt);
    lineEditLayout->addWidget(encTxt);

    midLayout->addLayout(labelLayout);
    midLayout->addLayout(lineEditLayout);
    mainLayout->addLayout(midLayout);
    mainLayout->addWidget(encButon);

}

Widget::~Widget()
{

}
