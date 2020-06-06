#ifndef LIST_MODEL_H
#define LIST_MODEL_H

#include <QAbstractListModel>
#include <QObject>
#include "epost.h"

class list_model : public QAbstractListModel
{
public:
    Q_OBJECT

public:
    list_model(QObject *parent = 0);
    ~list_model();

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;


//    QList<ePost> liste;
    vector<ePost*> liste;
public slots:
    void addValue(QString t, QString sb, QString bdy);
    void removeValue(QModelIndex index);


private:
};

#endif // LIST_MODEL_H
