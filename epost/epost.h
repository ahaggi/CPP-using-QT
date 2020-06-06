#ifndef EPOST_H
#define EPOST_H

#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <random>
#include<iomanip>
#include<QObject>

using namespace std;

class ePost
{



public:

    ePost(QString t, QString sb, QString bdy);
    ~ePost();
    QString tostring();
    QString to;
    QString subj;
    QString body;
};

#endif // EPOST_H
