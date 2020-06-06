#ifndef PERSON_H
#define PERSON_H

#include <iostream>
using namespace std;

class person{
public:
    string navn;
    person(){
        navn = "a";
    }


    person(person& p){
        *this = p;
    }



    person operator+(const person& p2){ //Det må stå en const

        person temp;
        temp.navn = this->navn + " "+p2.navn;
        return temp;  //return by value,,, dvs det blir retunert en kopi av "temp", og "temp" selv avsluttes
    }

};


class ex :public exception{
public:
    const char* what() const throw() {
        return "error error error...";
    }
};
#endif // PERSON_H
