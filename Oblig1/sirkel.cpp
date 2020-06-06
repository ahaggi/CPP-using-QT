#include"sirkel.h"
#include "heltall_bilde.h"


using namespace std;
const double PI = 3.1415926536;

    sirkel::sirkel(unsigned int r, unsigned int oY , unsigned int oX) {
        rad = r;
        origoX = oX;
        origoY= oY;
    }
/** Lag en instans av heltall_bilde, bruk lag_sirkler til å lage tre forskjellige sirkler med ulikt
    origo. Ingen av de tre sirklene kan ligge utenfor rammen til heltall_bilde.
    Verifiser ved å bruke Skriv_ut at metoden fungerer*/

    void sirkel::tegn_sirkel(heltall_bilde & htb, unsigned int r, unsigned int oY, unsigned int oX){
//        if (oX-r >=0 && oX+r < 64 && oY-r >= 0 && oY+r < 64 ) // sjekk ut at sirklen ligger ikke ut av rammen
        if (oX >=0 && oX < 64 && oY >= 0 && oY < 64 ) {
            for (int i = 0; i < 100; ++i) {
              unsigned int x = round(cos(i*7.5*PI/180)*r) +  oX;
              unsigned int y = round(sin(i*7.5*PI/180)*r) +  oY;
              cout << " x "<< x << " y "<< y << endl;
              htb.setBitenTilEn(y, x);
            }
            htb.skriv_ut();
        }


    }

