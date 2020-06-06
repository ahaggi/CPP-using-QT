#ifndef ANSATTDATA_H
#define ANSATTDATA_H
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include"person.h"
using namespace std;

class AnsattData : Person
{
public:
    AnsattData(string nv, unsigned int pn, Type t, unsigned int bnknr, unsigned int ln, char c);
    vector <Person> paarorende;
    unsigned int bank_konto;
    unsigned int loenn;
    char stilling_type;

    vector<Person>& get_paarorende();
    unsigned int get_bank_konto();
    unsigned int get_loenn();
    char get_stilling_type();
    void skriv_ut();

};

#endif // ANSATTDATA_H
