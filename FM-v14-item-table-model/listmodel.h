#ifndef LISTMODEL_H
#define LISTMODEL_H

#include <vector>
#include <QAbstractListModel>

class ListModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit ListModel(QObject *parent = 0);
    QVariant data(const QModelIndex &index, int role) const;
    int rowCount(const QModelIndex &parent) const;

signals:

public slots:
    void addValue();
    void removeValue(QModelIndex index);
private:
    std::vector<int> dataStore;  //Denne er containeren som innholder data, kun lage den med QList

};

#endif // MODEL_H
