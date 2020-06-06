#include <iostream>
#include <typeinfo>

using namespace std;

//Lag en funksjon som beregner fakultet til et heltall større eller lik null. Fakultetet til n er angitt med
//postfikset !. 0! = 1 (per definisjon), 1! = 1, 2! = 1*2, 3!=1*2*3, n! = 1*2*…*n
//Finn høyeste n som er mulig å beregne hvis datatypene for funksjonen er: short, unsigned short, int,
//unsigned int, long int, unsigned long int, long long int, unsigned long long int.
//(Oppgaven kan enten løses ved å benytte rekursive kall eller ved å lage en løkke.)
/**
# define INT8_MAX		(127)
# define INT16_MAX		(32767)
# define INT32_MAX		(2147483647)
# define INT64_MAX		(__INT64_C(9223372036854775807))

 Maximum of unsigned integral types.
# define UINT8_MAX		(255)
# define UINT16_MAX		(65535)
# define UINT32_MAX		(4294967295U)
# define UINT64_MAX		(__UINT64_C(18446744073709551615))

*/
void feilMelding(int n){
cout << "Kan ikke beregne mer enn " << n <<" fakulitet, for denne typen." <<  endl;
}


long long fakulitet (auto n){
     if (n==1 || n==0)
        return 1;
    long long  temp = 0;
    temp = n * fakulitet(--n);  // hvis du skriver n-1 isteden for --n, vil n blir kastet som vanlig int uansett hva slags int n var
                                // itilegg må du ta hansyn til forskjell mellom n-1 og --n i forhold til metode feilMelding(n)
    if ((typeid(n)  == typeid(short int)  && temp > INT16_MAX ) || (typeid(n)  == typeid(unsigned short int)  && temp > UINT16_MAX ) || (typeid(n)  == typeid(int)  && temp > INT32_MAX ) || (typeid(n)  == typeid(unsigned int)  && temp > UINT32_MAX)) {
        feilMelding(n);
        return 0;
    }else{
        return temp;
    }
 }


long long fakulitet1 (auto n){ // hvis det blir sendt en "long long int" til fakulitet metode, vil den beregne (n-1)! for en uklar årsak!!??
     if (n==1 || n==0)
        return 1;
    long long  temp = 0;
    auto forrigje = n;
    temp = n * fakulitet1(--forrigje);
    if ( (typeid(n)  == typeid(long long int)  && n ==20 )) {
        feilMelding(19);
        return 0;
    }else{
        return temp;
    }
 }


int main(int argc, char *argv[])
{
    int n = 8;
    short int x1 = n;
    short int f1 =  fakulitet(x1);
    cout << "fakulitet for short verdi "<< x1 <<" er lik " << f1 << endl << "-------------------------------------------"<< endl;

    unsigned short int x2 = n;
    unsigned short int f2 =  fakulitet(x2);
    cout << "fakulitet for unsigned short verdi"<< x2 <<" er lik " << f2 << endl << "-------------------------------------------"<<endl;

    int x3 = n;
    int f3 =  fakulitet(x3);
    cout << "fakulitet for int verdi"<< x3 <<" er lik " << f3 << endl << "-------------------------------------------"<<endl;

    unsigned int x4 = n;
    unsigned int f4 =  fakulitet(x4);
    cout << "fakulitet for unsigned int verdi"<< x4 <<" er lik " << f4 <<endl << "-------------------------------------------"<< endl;

    long long int x5 = n;
    long long int f5 =  fakulitet1(x5); // OBS burker ikke det samme metode her
    cout << "fakulitet for long verdi"<< x5 <<" er lik " << f5 << endl << "-------------------------------------------"<<endl;


    return 0;
}
