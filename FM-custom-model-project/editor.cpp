#include "editor.h"
#include <QtWidgets>

Editor::Editor(QWidget *parent) :
    QDialog(parent)
{   
    QGridLayout *gridLayout = new QGridLayout();
    QFormLayout *formLayout = new QFormLayout();
    setLayout(gridLayout);
    gridLayout->addLayout(formLayout, 0,0,2,2);

    stringEdit = new QLineEdit();
    formLayout->addRow("&String value:", stringEdit);
    intSpinBox = new QSpinBox();
    intSpinBox->setMinimum(0);
    intSpinBox->setMaximum(100);
    formLayout->addRow("&Integer value:", intSpinBox);
    okButton = new QPushButton("Ok");
    gridLayout->addWidget(okButton, 2, 0);
    cancelButton = new QPushButton("Cancel");
    gridLayout->addWidget(cancelButton, 2, 1);

    connect(okButton, SIGNAL(clicked()), this, SIGNAL(accepted()));
    connect(cancelButton, SIGNAL(clicked()), this, SIGNAL(rejected()));
}

void Editor::setString(QString s)
{
    stringEdit->setText(s);
}

void Editor::setInt(int i)
{
    intSpinBox->setValue(i);
}
