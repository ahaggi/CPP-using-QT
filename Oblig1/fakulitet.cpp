#include "fakulitet.h"



//Lag en funksjon som beregner fakultet til et heltall større eller lik null. Fakultetet til n er angitt med
//postfikset !. 0! = 1 (per definisjon), 1! = 1, 2! = 1*2, 3!=1*2*3, n! = 1*2*…*n
//Finn høyeste n som er mulig å beregne hvis datatypene for funksjonen er: short, unsigned short, int,
//unsigned int, long int, unsigned long int, long long int, unsigned long long int.
//(Oppgaven kan enten løses ved å benytte rekursive kall eller ved å lage en løkke.)

void fakulitet::feilMelding(int n){
cout << "Kan ikke beregne mer enn " << n-1 <<" fakulitet" << endl;
}


long long fakulitet::fakulitet_SHRT (short int n){
    if (n==1 || n==0)
        return 1;
    long long  temp = 0;
    temp =n * fakulitet_SHRT(n-1);

    if (temp > INT16_MAX ) {
        feilMelding(n);
        return 0;
    }else{
        return temp;

    }
 }
long long fakulitet::fakulitet_USHRT (unsigned short int n){
    if (n==1 || n==0)
        return 1;
    long long  temp = 0;
    temp =n * fakulitet_USHRT(n-1);

    if (temp > UINT16_MAX ) {
        feilMelding(n);
        return 0;
    }else{
        return temp;

    }
 }

long long fakulitet::fakulitet_INT (int n){
    if (n==1 || n==0)
        return 1;
    long long  temp = 0;
    temp =n * fakulitet_INT(n-1);

    if (temp > INT32_MAX ) {
        feilMelding(n);
        return 0;
    }else{
        return temp;

    }
 }
long long fakulitet::fakulitet_UINT (unsigned int n){
    if (n==1 || n==0)
        return 1;
    long long  temp = 0;
    temp =n * fakulitet_UINT(n-1);

    if (temp > UINT32_MAX ) {
        feilMelding(n);
        return 0;
    }else{
        return temp;

    }
 }

long long int fakulitet::fakulitet_LNG_ULNG (long long int n){
    if (n==1 || n==0)
        return 1;
    if (n>20) {
        feilMelding(n);
        return 0;
    }

    long long int  temp = 0;
    temp = n * fakulitet_LNG_ULNG(n-1);

        return temp;


 }



