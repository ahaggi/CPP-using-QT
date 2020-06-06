#include "widget.h"
#include <QApplication>
#include<cityEngine.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    cityEngine c;
    QString q =QString::fromStdString("z92");
    QString qsvar =c.get_country(q);
    string svar = qsvar.toStdString();
    cout << svar << endl;
    return a.exec();
}
