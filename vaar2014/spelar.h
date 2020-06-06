#ifndef SPELAR_H
#define SPELAR_H

#include<iostream>

using namespace std;

class spelar
{

    string namn;
    int poeng;

public:
    spelar();
    spelar(string n, int p);
    spelar(const spelar & s2);

    string finnNamn() const;
    void settNamn(string n);
    int finnPoeng()const;
    void settPoeng(int p);
    bool operator<(spelar& s2);
    bool operator>(spelar& s2);

};
    ostream & operator<<(ostream & os , const spelar& s2);

#endif // SPELAR_H
