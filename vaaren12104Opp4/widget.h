#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QLabel>
#include<QSpinBox>
#include<QLineEdit>
#include<QPushButton>
#include<QVBoxLayout>
#include<QHBoxLayout>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
    QLabel* offsetLabel;
    QLabel* inputLabel;
    QLabel* encLabel;

    QSpinBox* offsetTxt;
    QLineEdit* inputTxt;
    QLineEdit* encTxt;

    QPushButton * encButon;

    QVBoxLayout* labelLayout;
    QVBoxLayout* lineEditLayout;
    QHBoxLayout* midLayout;

    QVBoxLayout* mainLayout;







};

#endif // WIDGET_H
