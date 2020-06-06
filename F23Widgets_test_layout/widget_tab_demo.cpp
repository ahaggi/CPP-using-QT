#include "widget_tab_demo.h"

WidgetTabDemo::WidgetTabDemo(QWidget *parent) : QWidget(parent)
{
    tabs = new QTabWidget();
    hbox = new QHBoxLayout(this);

    tab_buttons_demo = new WidgetButtonDemo();
    tab_combo_slider_demo = new WidgetComboSliderDemo();
    tab_text_demo = new WidgetTextDemo();

    tabs->addTab(tab_buttons_demo, "Button demo");
    tabs->addTab(tab_combo_slider_demo, "Combo and slider demo");
    tabs->addTab(tab_text_demo, "Text demo");

    hbox->addWidget(tabs);
}
