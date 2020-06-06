#ifndef SPELAR_H
#define SPELAR_H
#include <string>
#include <iostream>

using namespace std;

class Spelar
{
private:
    string namn;
    int poeng;

public:
    Spelar();
    Spelar(string n, int p);
    Spelar(const Spelar& s);

    string finnNamn() const;
    int finnPoeng() const;
    void settNamn(string n);
    void settPoeng(int p);

    bool operator>(const Spelar& s) const;
    bool operator<(const Spelar& s) const;
    bool operator==(const Spelar& s) const;
};



#endif // SPELAR_H
