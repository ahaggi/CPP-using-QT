#include "tablemodel.h"

TableModel::TableModel(QObject *parent) :
    QAbstractTableModel(parent)
{
    dataStore.push_back(new Data(1, 'a'));
    dataStore.push_back(new Data(2, 'b'));
    dataStore.push_back(new Data(3, 'c'));
}

QVariant TableModel::data(const QModelIndex &index, int role) const
{
    if(role == Qt::DisplayRole){
        switch (index.column()) {
        case 0:
            return dataStore.at(index.row())->tall;
        case 1:
            // QVariant kan ikke holde på en char, så vi konverterer til QString
            return QString(dataStore.at(index.row())->tegn);

        default:
            return QVariant();
        }
    }

    return QVariant();

}

int TableModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return dataStore.size();
}

int TableModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return 2;
}

QVariant TableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Horizontal) {
        switch (section) {
        case 0:
            return QString("Tall");

        case 1:
            return QString("Tegn");

        default:
            return QVariant();
        }
    }
    return QVariant();
}
