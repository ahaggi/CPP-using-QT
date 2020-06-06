#ifndef FAKULITET_H
#define FAKULITET_H
#include <iostream>

using namespace std;


class fakulitet
{
public:

//Lag en funksjon som beregner fakultet til et heltall større eller lik null. Fakultetet til n er angitt med
//postfikset !. 0! = 1 (per definisjon), 1! = 1, 2! = 1*2, 3!=1*2*3, n! = 1*2*…*n
//Finn høyeste n som er mulig å beregne hvis datatypene for funksjonen er: short, unsigned short, int,
//unsigned int, long int, unsigned long int, long long int, unsigned long long int.
//(Oppgaven kan enten løses ved å benytte rekursive kall eller ved å lage en løkke.)

static void feilMelding(int n);


static long long fakulitet_SHRT (short int n);
static long long fakulitet_USHRT (unsigned short int n);

static long long fakulitet_INT (int n);
static long long fakulitet_UINT (unsigned int n);

static long long int fakulitet_LNG_ULNG (long long int n);

};

#endif // FAKULITET_H
