#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

enum Type {SUPER_MENTOR, MENTOR, IKKE};
class Person
{
public:

    Person(string nv, unsigned int pn, Type t);

    Person * tilknyttet;
    string navn;
    unsigned int pnr;
    Type type;
    unsigned int antall_tilknyttet;

    Person get_tilknyttet();
    string get_navn();
    unsigned int get_pnr();
    Type get_type();
    unsigned int get_antall_tilknyttet();

    bool kan_legge_en_som_mentor(Person mntr);
    void set_tilknyttet(Person mntr);
    void set_navn(string nv);
    void set_pnr(unsigned int pn);
    void set_type(Type t);
    void set_antall_tilknyttet(unsigned int ant);



    void skriv_ut();
};

#endif // PERSON_H
