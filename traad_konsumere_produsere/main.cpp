#include <iostream>
#include <thread>
#include<vector>


//#include <stdlib.h>
//#include <ctime>
//#include<iomanip>

using namespace std;


void vent (int sek){
    chrono::milliseconds tid(sek);
    this_thread::sleep_for(tid);
}


int bank_konto = 1;
//srand(time(0));

void legg_til_saldo(int klient_id){
    cout << "Klient id: "<< klient_id << ", saldo: " << bank_konto << endl;
    bank_konto+= (rand()% 10) + 1;
    cout << "Klient id: "<< klient_id << ", saldo: " << bank_konto << endl;
}

void trekke_fra_saldo(int klient_id){
    cout << "Klient id: "<< klient_id << ", saldo: " << bank_konto << endl;
    while (bank_konto<0) vent(100);
    bank_konto-= (rand()% 10) + 1;
    cout << "Klient id: "<< klient_id << ", saldo: " << bank_konto << endl;
}
int main(int argc, char *argv[])
{
    vector <thread> produsere;
    vector <thread> konsumere;
    for (int var = 0; var < 50 ; ++var) {
        // OBS det blir feil hvis du skriver thread t(legg_til_saldo,var); klienter.push_back(t)
        produsere.push_back(thread (legg_til_saldo,var));
        konsumere.push_back(thread (trekke_fra_saldo,var));
    }

    for (int var = 0; var < 50; ++var) {
        produsere[var].join();
        konsumere[var].join();
    }
    return 0;
}
