// Eksempel på bruk av QSignalMapper.
// Hver knapp i det numeriske tastaturet er tilknyttet en verdi,
// og vi ønsker et signal med denne verdien som parameter når
// knappen trykkes, men clicked() signalet gir ikke ut en int.
// QSignalMapper er derfor brukt for å "mappe" en verdi

#include "numerickeyboardwidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    NumericKeyboardWidget w;
    w.show();

    return a.exec();
}
