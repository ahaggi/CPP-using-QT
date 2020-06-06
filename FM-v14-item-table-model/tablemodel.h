#ifndef TABLEMODEL_H
#define TABLEMODEL_H

#include <QAbstractTableModel>
#include <vector>

class Data {
public:
    Data(int i, char c){ tall = i; tegn = c; }
    int tall;
    char tegn;
};

class TableModel : public QAbstractTableModel // QAbstractTableModel extends QAbstractItemModel
{
    Q_OBJECT
public:
    explicit TableModel(QObject *parent = 0);
    QVariant data(const QModelIndex &index, int role) const;
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;

signals:

public slots:

private:
    std::vector<Data*> dataStore;
};

#endif // TABLEMODEL_H
