#include <iostream>
#include <stdlib.h>
#include <ctime>
#include<iomanip>

using namespace std;



int main(int argc, char *argv[])
{
    int innsats = 1024;
    int utfall = 0;

    srand(time(NULL));
    cout << setw(3)<< "tur " << setw(10)<< "innsats " << setw(20) << "utfall(tap/gevinst) " << setw(10) << "beholdning " << endl;

    for (int i = 0; i < 10 && innsats>1; ++i) {
        utfall =(rand() % 2 == 1)? -innsats/2: innsats/2;
        innsats = innsats+utfall;
        cout << setw(3)<< i << setw(10)<<  innsats-utfall << setw(20) << utfall << setw(10) << innsats << endl;
    }


//tur, innsats, utfall(tap/gevinst) og beholdning

    return 0;

}
