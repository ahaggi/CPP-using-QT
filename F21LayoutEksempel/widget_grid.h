#ifndef WIDGET_GRID_H
#define WIDGET_GRID_H

#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QRadioButton>

class Widget_grid : public QWidget
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

    QGridLayout* grid_layout;

public:
    Widget_grid(QWidget *parent = 0);
    ~Widget_grid();
};

#endif // WIDGET_GRID_H
