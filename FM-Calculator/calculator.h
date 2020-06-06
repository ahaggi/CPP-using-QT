#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>

class noe : public QWidget
{
    Q_OBJECT
public:
    enum operators {MINUS = -1, PLUS = 1};
    noe();
private:
    int operand, memory;
    operators opr;
    QPushButton* buttons[10];
    QPushButton *btnPlus, *btnMinus, *btnEquals, *btnClear;
    QLineEdit* lineDisplay;

public slots:
    void keyPressed(int);
    void keyPressed(QString);
};

#endif // CALCULATOR_H
