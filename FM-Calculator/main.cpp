#include <QApplication>
#include "calculator.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    noe calc;

    calc.show();

    return app.exec();
}
