#ifndef CALCULATORGUI_H
#define CALCULATORGUI_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include "calculator.h"

class CalculatorGui : public QWidget
{
    Q_OBJECT
public:
    explicit CalculatorGui(
            QWidget *parent = 0);

private:
    noe* calculator;
    QPushButton* buttons[10];
    QPushButton *btnPlus, *btnMinus;
    QPushButton *btnEquals, *btnClear;
    QLineEdit* lineDisplay;
public slots:
    void changeValue(int);

};


#endif // CALCULATORGUI_H
