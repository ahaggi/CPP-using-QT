#ifndef COUNTRY_H
#define COUNTRY_H
#include <iostream>
#include<city.h>
#include<vector>
#include <string>
#include <stdlib.h>
#include<iomanip>
#include<algorithm>

using namespace std;


class country{

public:
    string name;
    vector<city*> cities;
    //flag
    country(string nm);
    city *findCity(string c);
};

#endif // COUNTRY_H
