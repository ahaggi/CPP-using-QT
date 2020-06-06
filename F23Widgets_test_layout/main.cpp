// Demonstrasjon av bruk av diverse widgets i Qt
//
// Merk:
// Programmet forventer at ikonet og bildet skal ligge på et mappenivå
// over mappen hvor programmet kjører ifra.
// Hvis dette ikke fungerer må en kanskje flytte på bildet/ikonet på
// disken, eller endre på filnavnet og banen hvor ikonet og bildet settes
// (iconButton->setIcon(QIcon("../play-icon.ico")) i widget_button_demo.cpp,
//  og HTML strengen i widget_text_demo.cpp).

#include "widget_button_demo.h"
#include "widget_text_demo.h"
#include "widget_combo_slider_demo.h"
#include "widget_tab_demo.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    WidgetButtonDemo w1;
    WidgetTextDemo w2;
    WidgetComboSliderDemo w3;
    WidgetTabDemo w4;

    w1.setWindowTitle("Diverse buttons widget demonstrasjon");

    w2.setGeometry(500,500,600,700);
    w2.setWindowTitle("Text edit widget demonstrasjon");

    w3.setWindowTitle("Combo og slider widget demonstrasjon");

    w4.setWindowTitle("Tab widget demonstrasjon");

    w1.show();
    w2.show();
    w3.show();
    w4.show();

    return a.exec();
}
