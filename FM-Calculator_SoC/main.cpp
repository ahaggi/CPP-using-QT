#include <QApplication>
#include <QtWidgets>
#include "calculatorgui.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    CalculatorGui calc;

    calc.show();

    return app.exec();
}
