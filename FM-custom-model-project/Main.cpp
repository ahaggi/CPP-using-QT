#include <QtWidgets>
#include "custommodel.h"
#include "customtablemodel.h"
#include "customdelegate.h"



int main( int argc, char **argv ){

    QApplication app(argc, argv);



    QTableView tableView;

    CustomTableModel tableModel;

    CustomDelegate delegate(&tableView);

    tableView.setModel(&tableModel);
    tableView.setItemDelegate(&delegate);
    tableView.setSelectionBehavior(QAbstractItemView::SelectRows);
    tableView.show();

//    QPushButton btnInsert("Insert");
//    QObject::connect(&btnInsert, SIGNAL(clicked()), &tableModel, SLOT(insertRows()));
//    btnInsert.show();

    return app.exec();
}

