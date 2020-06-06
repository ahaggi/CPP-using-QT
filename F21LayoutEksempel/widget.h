#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QRadioButton>

class Widget : public QWidget
{
    Q_OBJECT

    QPushButton* button1;
    QPushButton* button2;
    QPushButton* button3;
    QPushButton* button4;

    QRadioButton* rbutton1;
    QRadioButton* rbutton2;
    QRadioButton* rbutton3;
    QRadioButton* rbutton4;

    QHBoxLayout* hbox1;
    QHBoxLayout* hbox2;
    QVBoxLayout* vbox;

public:
    Widget(QWidget *parent = 0);
    ~Widget();
};

#endif // WIDGET_H
