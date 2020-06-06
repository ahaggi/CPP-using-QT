#ifndef SPEL_GRENSE_H
#define SPEL_GRENSE_H

#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <random>
#include<iomanip>



using namespace std;

class spel_grense
{

public:



    virtual int get_antall_forsoek()=0;
    virtual void oek_antall_forsoek()=0;
    virtual void nullstill_antall_forsoek()=0;
    virtual int get_ny_rett()=0;
    virtual int get_rett()=0;
};


#endif // SPEL_GRENSE_H
