#ifndef WIDGET_TAB_DEMO_H
#define WIDGET_TAB_DEMO_H

#include <QWidget>
#include <QTabWidget>
#include <QHBoxLayout>
#include "widget_button_demo.h"
#include "widget_combo_slider_demo.h"
#include "widget_text_demo.h"

class WidgetTabDemo : public QWidget
{
    Q_OBJECT

private:
    QTabWidget* tabs;
    WidgetButtonDemo* tab_buttons_demo;
    WidgetComboSliderDemo* tab_combo_slider_demo;
    WidgetTextDemo* tab_text_demo;

    QHBoxLayout* hbox;

public:
    explicit WidgetTabDemo(QWidget *parent = 0);

signals:

public slots:
};

#endif // WIDGET_TAB_DEMO_H
