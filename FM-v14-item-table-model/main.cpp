#include <QApplication>
#include <QtWidgets>
#include "listmodel.h"
#include "tablemodel.h"
#include<iostream>

using namespace std;

int main(int argc, char *argv[])
{

    QApplication app(argc, argv);

    QListView listView;
    ListModel m;
    listView.setModel(&m);
//    QObject::connect(&listView, SIGNAL(doubleClicked(QModelIndex)), &m,SLOT(removeValue(QModelIndex)));
    QObject::connect(&listView, SIGNAL(clicked(QModelIndex)), &m,SLOT(addValue()));
    listView.show();


    QTableView tableView;
    TableModel tableModel;
    tableView.setModel(&tableModel);
    tableView.show();

    return app.exec();
}

/* OBS
 * HVIS ptr PEKER PÅ char-type ==> KAN IKKE FÅ TAK I VARIABELEN-ADRESSE VED Å SKRIVE &ch ISTEDENFOR ptr
 *
 * PGA AT ptr er void-pointer ==> KAN IKKE FÅ TAK I VARIABELEN-VERDI VED Å SKRIVE *ptr ISTEDENFOR x eller ch
 * error: ‘void*’ is not a pointer-to-object type
/*

Output
Address of 'x' : 0x7ffca9b45f14 and Value of 'x' : 9
Address of 'x' : 0x7ffca9b45f14 equivalent to : 0x7ffca9b45f14
Address of 'ch' : 0x7ffca9b45f13 and Value of 'ch' : a
Address of 'ch' : 0x7ffca9b45f13 equivalent to : a 	//OBS KAN IKKE BRUKE &ch ISTEDENFOR ptr
*/


