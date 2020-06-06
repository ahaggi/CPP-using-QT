#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QObject>

class noe : public QObject
{
    Q_OBJECT
public:
    explicit noe();
    enum operators {MINUS = -1,
                PLUS = 1};
private:
    int operand, memory;
    operators opr;
public slots:
    void keyPressed(int);
    void keyPressed(QString);
signals:
    void valueChanged(int);
};

#endif // CALCULATOR_H
