#include "person.h"

    Person::Person(string nv, unsigned int pn, Type t)
    {
        navn= nv;
        pnr=pn;
        type=t;
        antall_tilknyttet=0;
    }

    Person Person::get_tilknyttet(){
        return *tilknyttet;
    }
    string Person::get_navn(){
        return navn;
    }
    unsigned int Person::get_pnr(){
        return pnr;
    }
    Type Person::get_type(){
        return type;
    }
    unsigned int Person::get_antall_tilknyttet(){
        return antall_tilknyttet;
    }

    bool Person::kan_legge_en_som_mentor( Person  mntr){
        return ((mntr.get_antall_tilknyttet() <= 10) && (this->type!=Type::SUPER_MENTOR)) ? true : false ;
    }

    void Person::set_tilknyttet(Person  mntr){
        if (tilknyttet != NULL) {
            tilknyttet->set_antall_tilknyttet((tilknyttet->get_antall_tilknyttet())-1);
        }else{

            if (kan_legge_en_som_mentor(mntr)) {
                tilknyttet = & mntr;

                tilknyttet->set_antall_tilknyttet((tilknyttet->get_antall_tilknyttet())+1);

            }else
                cout << "Feilmelding Denne person obj er av type superMentor \n";

        }
    }

    void Person::set_navn(string nv){
        navn=nv;
    }

    void Person::set_pnr(unsigned int pn){
        pnr=pn;
    }

    void Person::set_type(Type t){
        type=t;
    }

    void Person::set_antall_tilknyttet(unsigned int ant){
        antall_tilknyttet=ant;
    }


    void Person::skriv_ut(){
        string str=" ";
        if (type != Type::IKKE) {
            str=", Antall tilknytning: " + to_string(antall_tilknyttet);
        }
        cout<< "Navn: "<< get_navn() << ", Pnr:" <<  to_string(get_pnr()) << ", Type: " << to_string(get_type()) << str << endl ;
    }


