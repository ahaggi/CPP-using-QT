#include "listmodel.h"

ListModel::ListModel(QObject *parent) :
    QAbstractListModel(parent)
{
    dataStore.push_back(10);
    dataStore.push_back(9);
    dataStore.push_back(11);
}

QVariant ListModel::data(const QModelIndex &index, int role) const
{
    // TODO
    /** *****/
    if (role == Qt::DisplayRole) {
        return dataStore.at(index.row());  //OBS index.row retunere int
    }else{
        return QVariant(); // ikke Null objekt,men tom objekt
    }

}

int ListModel::rowCount(const QModelIndex &parent) const
{
    /** *****/
    // TODO
    return dataStore.size();
}


//*****slots***********

void ListModel::addValue(){
    int row = dataStore.size();
    //apend rows (QModelIndex(), 3 , 5) = append 3 rows at index 3,4 og 5
    //apend rows (QModelIndex(), 7 , 7) = append only one row at index 7
    beginInsertRows(QModelIndex(), row, row);
    dataStore.push_back(13);
    endInsertRows();
}

void ListModel::removeValue(QModelIndex index){
    int row = index.row();
    beginRemoveRows(QModelIndex(), row, row);
    dataStore.erase(dataStore.begin()+row);
    endRemoveRows();
}
