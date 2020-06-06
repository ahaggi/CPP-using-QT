#include "spelar.h"

spelar::spelar()
{
    namn = "";
    poeng = 0;
}
spelar::spelar(string n, int p)
{
    namn = n;
    poeng = p;
}


spelar::spelar(const spelar &s2){
    *this = s2;
}

string spelar::finnNamn() const{
    return namn;
}

void spelar::settNamn(string n){
    namn = n;
}

int spelar::finnPoeng()const{
    return poeng;
}

void spelar::settPoeng(int p){
    poeng = p;
}

bool spelar::operator<(spelar& s2){
    return this->poeng <s2.poeng;
}

bool spelar::operator>(spelar& s2){
    return this->poeng > s2.poeng;
}

ostream& operator<<(ostream & os , const spelar& s2){
    os << "Namn= " << s2.finnNamn() << ", poeng= " << s2.finnPoeng();
    return os;
}

