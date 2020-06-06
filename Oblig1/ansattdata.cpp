#include "ansattdata.h"

AnsattData::AnsattData(
        string nv, unsigned int pn, Type t, unsigned int bnknr, unsigned int ln, char c) : Person(nv, pn, t)
{
    bank_konto=bnknr;
    loenn=ln;
    stilling_type =c;

}

vector<Person>& AnsattData::get_paarorende(){
    return paarorende;
}
unsigned int AnsattData::get_bank_konto(){
    return bank_konto;
}
unsigned int AnsattData::get_loenn(){
    return loenn;
}
char AnsattData::get_stilling_type(){
    return stilling_type;
}

void AnsattData::skriv_ut(){
    Person::skriv_ut();
     cout << "bank konto nr: " << to_string(bank_konto) << ", lønn: " << to_string(loenn) << ", stiling_type: "<< to_string(stilling_type) << "\n\n";

}
