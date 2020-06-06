#include<country.h>

country::country(string nm){
    name = nm;
    cout << name<< endl;
    for (int i = 0; i < 10; ++i) {
        cities.push_back(new city(nm + to_string(i), i , 1.5 * double(i)) );
    }
}

city* country::findCity(string cityName){

    vector<city*>::iterator it= find_if(cities.begin(),cities.end(), [cityName](city* c){ return c->name == cityName;});

    return (it!=cities.end())?*it:NULL;
    
    
}
