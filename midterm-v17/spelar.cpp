#include "spelar.h"

Spelar::Spelar()
{
    namn = "";
    poeng = 0;
}

Spelar::Spelar(std::string n, int p):namn(n) ,poeng(p)
{

}

Spelar::Spelar(const Spelar &s)
{
    namn = s.namn;
    poeng = s.poeng;
}

string Spelar::finnNamn() const
{
    return namn;
}

int Spelar::finnPoeng() const
{
    return poeng;
}

void Spelar::settNamn(string n)
{
    namn = n;
}

void Spelar::settPoeng(int p)
{
    poeng = p;
}

bool Spelar::operator>(const Spelar &s) const
{
    return poeng > s.poeng;
}

bool Spelar::operator<(const Spelar &s) const
{
    return poeng < s.poeng;
}

bool Spelar::operator==(const Spelar &s) const
{
    return poeng == s.poeng;
}



