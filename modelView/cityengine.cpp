#include <cityEngine.h>;


cityEngine::cityEngine(){

    for (int i = 0; i < 26; ++i) {
        string nm;
        nm.push_back(char(i+97));

        list.push_back(new country(nm));
    }
}


country* cityEngine::find_country(QString & cityName){
    string cn = cityName.toStdString();
    vector<country*>::iterator it  = list.begin();
    bool funnet = false;
    while(it!=list.end() && !funnet) {
       funnet=(**it).findCity(cn) != NULL;
       if (!funnet) {
           ++it;
       }
    }
    return (it != list.end())?(*it):NULL;

}


QString cityEngine::get_country(QString & cityName){
    country* cnt = find_country(cityName);

//You can; the null pointer is implicitly converted into boolean false while non-null pointers are converted into true. From the C++11 standard, section on Boolean Conversions:

    if (cnt) {
        string temp  = cnt->name;
        QString countryName = QString::fromStdString(temp);
        return countryName;
    }

    QString countryName = QString::fromStdString("fins ikke");
    return countryName;




}

int cityEngine::population(QString & cityName){
    country* cnt = find_country(cityName);
    if (cnt) {
        city* ci = cnt->findCity(cityName.toStdString());
        return ci->population;
    }
    return -1;

}

qreal cityEngine::area(QString & cityName){
    country* cnt = find_country(cityName);
    if (cnt) {
        city* ci = cnt->findCity(cityName.toStdString());
        return ci->area;
    }
    return -1;

}
QStringList cityEngine::countries(){
    vector<country*>::iterator it = list.begin();
    QStringList countriesNames;

    while (it != list.end()) {
        countriesNames << QString::fromStdString((**it).name);
    }

    return countriesNames;
}
QStringList cityEngine::cityByCountry(QString & countryName){
    QStringList countriesNames;

    for (vector<country*>::iterator it = list.begin(); it != list.end(); ++it) {
        bool funnet=(**it).findCity(countryName.toStdString()) != NULL;
        if (funnet)
            countriesNames << QString::fromStdString((**it).name);
    }

    return countriesNames;
}
