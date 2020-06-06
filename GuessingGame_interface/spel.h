#ifndef SPEL_H
#define SPEL_H

#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <random>
#include<iomanip>
#include"spel_grense.h"



using namespace std;

class spel : public spel_grense
{

public:
    spel();
    ~spel();
    int rett=-1;
    int antall_forsoek=0;


    int get_antall_forsoek();
    void oek_antall_forsoek();
    void nullstill_antall_forsoek();
    int get_ny_rett();
    int get_rett();
};


#endif // SPEL_H
