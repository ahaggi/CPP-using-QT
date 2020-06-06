#ifndef ITEMCLASS_H
#define ITEMCLASS_H
#include <QString>
#include <QDataStream>

class ItemClass
{
public:
    ItemClass(QString s = "", int i = 0);
    QString getStr() const;
    int getNr() const;
    bool setStr(const QString s);
    bool setNr(const int i);
    QString toString() const;
private:
    QString str;
    int nr;
};

QDataStream& operator<<(QDataStream& ds, const ItemClass& item);

#endif // ITEMCLASS_H
