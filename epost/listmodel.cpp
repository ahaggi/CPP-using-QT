#include "listmodel.h"

list_model::list_model(QObject *parent)
    : QAbstractListModel(parent)
{
    for (int var = 0; var < 10; ++var) {
        QString to = "to "+QString::number(var);
        QString sb="subject "+ QString::number(var);
        QString bdy="msg "+QString::number(var);
        liste.push_back(new ePost(to , sb , bdy ));
    }
}
list_model::~list_model(){
    vector<ePost*>::iterator it = liste.begin();
    while (it != liste.end()) {
        delete(*it);
        liste.erase(it);
    }
}

int list_model::rowCount(const QModelIndex &parent) const
{
    return liste.size();
}

QVariant list_model::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole)
        return (liste.at(index.row()))->tostring();  //OBS index.row retunere epost
     else
        return QVariant();
}

void list_model::addValue(QString t, QString sb, QString bdy){
    int row = liste.size();

    beginInsertRows(QModelIndex(), row, row);
        liste.push_back(new ePost(t , sb , bdy ));
    endInsertRows();
}

void list_model::removeValue(QModelIndex index){
    int row = index.row();

    beginRemoveRows(QModelIndex(), row, row);
        vector<ePost*>::iterator it = liste.begin()+row;
        delete (*it);
        liste.erase(liste.begin()+row);
    endRemoveRows();
}
