#ifndef heltall_bilde_H
#define heltall_bilde_H
#include <iostream>
#include<bitset>
#include <cmath>
#include <vector>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include "heltall_bilde.h"
using namespace std;

enum  Fil_format{Tall, Tekst, Bin};

class heltall_bilde
{
public:
    heltall_bilde() ;

     vector<unsigned long long> heltall_vektor;

     void Lagre_bilde(const string & , Fil_format );

     void Les_bilde(const string& , Fil_format );

     void skriv_ut();

     void setBitenTilEn(unsigned int , unsigned int );

     void lag_bilde(char b);
     void lag_bilde(char b, int y);

     bool operator==(heltall_bilde & v2);

     void operator|(heltall_bilde & v2);

     void operator~();


};

#endif // heltall_bilde_H
