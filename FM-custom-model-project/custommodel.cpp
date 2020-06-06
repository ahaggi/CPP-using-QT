#include "custommodel.h"
#include <QtGui>
CustomModel::CustomModel(QObject *parent) :
    QAbstractListModel(parent)
{
    for(int i = 0; i < 5; i++){

        list.append(QString::number(i));
    }
}

int CustomModel::rowCount(const QModelIndex &parent) const
{
    return list.size();
}

QVariant CustomModel::data(const QModelIndex &index, int role) const
{
    if(role == Qt::DisplayRole)
        return list.at(index.row());
    else
        return QVariant();
}
