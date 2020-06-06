#include "widget.h"
#include "widget_grid.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    Widget_grid w_grid;
    w.show();
    w_grid.show();

    return a.exec();
}
