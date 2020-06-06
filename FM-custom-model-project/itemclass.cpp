#include "itemclass.h"

ItemClass::ItemClass(QString s, int i)
{
    str = s;
    nr = i;
}

QString ItemClass::getStr() const
{
    return str;
}

int ItemClass::getNr() const
{
    return nr;
}

bool ItemClass::setStr(const QString s)
{
    str = s;
    return true;
}

bool ItemClass::setNr(const int i)
{
    return (nr = i);
}

QString ItemClass::toString() const
{
    return QString("%0 %1").arg(str).arg(nr);
}


QDataStream& operator<<(QDataStream& ds, const ItemClass& item)
{
    ds << item.getNr() << item.getStr();
    return ds;
}
