#include <QApplication>
#include <QListView>
#include <QStringListModel>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QListView* w = new QListView();
    QStringList list;
    list << "One" << "Two" << "Three" << "Four";
    QStringListModel* m = new QStringListModel(list);

    w->setModel(m);
    w->show();

    return a.exec();
}
