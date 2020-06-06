// Eksempel på arkitektur - Høy kobling mellom lag
//
// Dette programmet analyserer teksten en skriver inn i en tekstboks, og
// teller og lister opp hvor ofte de forskjellige ordene i teksten forekommer.
//
// Dette er et eksempel med HØY kobling mellom lagene
//
// Programmets lagstruktur:
//
// +-------------------------------------------------+
// |                                                 |
// |            GUI (TextStatsWidget)                |
// |                                                 |
// +-------------------------------------------------+
//                        |
//                        |
//                       \ /
// +-------------------------------------------------+
// |                                                 |
// |          Tekst analyse (textStats)              |
// |                                                 |
// +-------------------------------------------------+



#include "textstatswidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TextStatsWidget w;
    w.show();
    w.setWindowTitle("Tekst statistikk eksempel - Høy kobling");

    return a.exec();
}
