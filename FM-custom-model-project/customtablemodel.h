#ifndef CUSTOMTABLEMODEL_H
#define CUSTOMTABLEMODEL_H

#include <QAbstractTableModel>
#include "itemclass.h"

class CustomTableModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit CustomTableModel(QObject *parent = 0);

    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role);
    Qt::ItemFlags flags(const QModelIndex &index) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;

    void lagreKunderTilFil();

public slots:
    bool insertRows ( int row = 0, int count = 1, const QModelIndex & parent = QModelIndex());
    bool removeRows ( int row, int count, const QModelIndex & parent = QModelIndex());

private:
    QList<ItemClass> valueList;
};

#endif // CUSTOMTABLEMODEL_H
