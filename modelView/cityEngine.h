#ifndef CITY_ENGINE_H
#define CITY_ENGINE_H
#include<QObject>
#include<vector>
#include <string>
#include <stdlib.h>
#include<iostream>
#include<country.h>

using namespace std;

class cityEngine: public QObject
{
    Q_OBJECT

public:

    vector<country*> list;

    cityEngine();


    QStringList cities();

    QString get_country(QString & cityName);

    int population(QString & cityName);
    

    qreal area(QString & cityName);

    QIcon flag(QString & countryName);

    QStringList countries();

    QStringList cityByCountry(QString & countryName);



    /** ******************/
    country* find_country(QString & cityName);


};

#endif // CITY_ENGINE_H
