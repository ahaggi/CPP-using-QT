#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QLayout>

#include "colorchangeradt.h"
#include "colormanager.h"

namespace Ui {
class Widget;
}

class spel_gui : public QWidget
{
    Q_OBJECT

public:
    explicit spel_gui(QWidget *parent = 0);
    ~spel_gui();

public slots:
    void updateColor();

    void updateColorHighCoupling();
    void updateColorHighestCoupling();

private:
    Ui::Widget *ui;

    colorChangerADT * changer;
    colorManager * manager;
};

#endif // WIDGET_H
