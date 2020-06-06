// Eksempel på sammenkobling av valueChanged signal og
// setValue slot på QDial. QDial er implementert med en sjekk
// for om verdien faktisk er endret før en sender ut valueChanged
// signalet. Dette er viktig å huske når en definerer egne signals/slots,
// for å unngå evige signalløkker i våre programmer.

#include "dialwidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DialWidget w;
    w.show();

    return a.exec();
}
