#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <cityEngine.h>
#include <QAbstractItemModel>


class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

    cityEngine cityEng;

};

#endif // WIDGET_H
