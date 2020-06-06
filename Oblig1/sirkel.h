#ifndef SIRKEL_H
#define SIRKEL_H



#include "sirkel.h"
#include "heltall_bilde.h"
using namespace std;

class sirkel{

private:
    unsigned int rad;
    unsigned int origoX;
    unsigned int origoY;

public:
    sirkel(unsigned int r, unsigned int oY , unsigned int oX) ;
    void tegn_sirkel(heltall_bilde & htb, unsigned int r, unsigned int oY, unsigned int oX);
};


#endif // SIRKEL_H
