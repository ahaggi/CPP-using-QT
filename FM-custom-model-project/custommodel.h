#ifndef CUSTOMMODEL_H
#define CUSTOMMODEL_H

#include <QAbstractListModel>
#include <QList>
#include <QtGui>
#include "itemclass.h"

class CustomModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit CustomModel(QObject *parent = 0);
    
    int rowCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;

signals:
    
public slots:

private:
    QList<QString> list;
};

#endif // CUSTOMMODEL_H
