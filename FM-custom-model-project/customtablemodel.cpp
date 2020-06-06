#include "customtablemodel.h"
#include <QtGui>

CustomTableModel::CustomTableModel(QObject *parent) :
    QAbstractTableModel(parent)
{
    for(int i = 0; i < 5; i++){

        valueList.append(ItemClass("A",i));
    }
}

int CustomTableModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return valueList.size();
}

int CustomTableModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return 2;
}

QVariant CustomTableModel::data(const QModelIndex &index, int role) const
{
    switch(role){
    case Qt::DisplayRole:
        if(index.column() == 0){
            return valueList.at(index.row()).getStr();
        }
        else {
            return valueList.at(index.row()).getNr();
        }
        break;
    case Qt::EditRole:
        if(index.column() == 0){
            return valueList.at(index.row()).getStr();
        }
        else {
            return valueList.at(index.row()).getNr();
        }
        break;
    default:
        return QVariant();
    }
}

QVariant CustomTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Horizontal) {
        switch(section){
        case 0:
            return tr("Value");
            break;
        case 1:
            return tr("Value 2");
            break;
        default:
            return QVariant();
        }
    }
    else {
        return QVariant();
    }
}

void CustomTableModel::lagreKunderTilFil()
{
    QFile file("out.txt");
    if (!file.open(QIODevice::WriteOnly))
        return;

    QDataStream dataOutStream(&file);
    dataOutStream.setVersion(QDataStream::Qt_4_8);
    dataOutStream << valueList;
}

bool CustomTableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    bool dataSet = false;
    int row = index.row();
    if(role == Qt::EditRole){
        if(index.column() == 0)
            dataSet = valueList[row].setStr(value.toString());
        else {
            dataSet = valueList[row].setNr(value.toInt());
        }
        emit dataChanged(index, index);
    }
    return dataSet;
}

Qt::ItemFlags CustomTableModel::flags(const QModelIndex &index) const
{
    return QAbstractTableModel::flags(index) | Qt::ItemIsEditable;
}

bool CustomTableModel::insertRows(int row, int count, const QModelIndex &parent)
{
    beginInsertRows(parent, row, row+count-1);
    for(int i = 0; i < count; i++){
        valueList.insert(row, ItemClass());
    }
    endInsertRows();
    return true;
}

bool CustomTableModel::removeRows(int row, int count, const QModelIndex &parent)
{
    beginRemoveRows(parent, row, row+count-1);
    for(int i = 0; i < count; i++){
        valueList.removeAt(row);
    }
    endRemoveRows();
    return true;
}


