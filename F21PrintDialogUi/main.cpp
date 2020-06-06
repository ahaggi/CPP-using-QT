#include "printdialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PrintDialog w;
    w.show();

    return a.exec();
}
