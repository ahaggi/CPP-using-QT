#include "heltall_bilde.h"


    heltall_bilde::heltall_bilde() {
        heltall_vektor.assign(64,0);
     }

    void heltall_bilde::Lagre_bilde(const string & filNavn, Fil_format fil_format){

        ofstream fil {filNavn};

        if (fil) {

        if (fil_format==Fil_format::Tall) {
            for (unsigned int i = 0; i < heltall_vektor.size(); ++i) {
                fil << setw(2)<< setfill('0') << i << " - " << (heltall_vektor[i]) << endl;
             }

        }else if (fil_format==Fil_format::Tekst) {
            for (unsigned int i = 0; i < heltall_vektor.size(); ++i) {
                bitset<64>c (heltall_vektor[i]);
                fil << setw(2)<< setfill('0') << i << " - " << c.to_string('_', 'W') << endl;
             }

        }else if (fil_format==Fil_format::Bin) {
            for (unsigned int i = 0; i < heltall_vektor.size(); ++i) {
                bitset<64>c (heltall_vektor[i]);
                fil << setw(2)<< setfill('0') << i << " - " << c.to_string() << endl;
             }

        }
        }

    }
    void heltall_bilde::Les_bilde(const string & filNavn, Fil_format fil_format){
        ifstream fil {filNavn};

        if (fil) {

        if (fil_format==Fil_format::Tall) {
            for (unsigned int i = 0; i < heltall_vektor.size(); ++i) {
                char a,b,c;
                fil >> a >> b >> c;
                fil >>(heltall_vektor[i]);

             }

        }else if (fil_format==Fil_format::Tekst) {
            for (unsigned int i = 0; i < heltall_vektor.size(); ++i) {
                char a,b,c;
                fil >> a >> b >> c;
                string e;
                fil >> e;
                replace( e.begin(), e.end(), '_', '0');
                replace( e.begin(), e.end(), 'W', '1');
                heltall_vektor[i]= ( bitset<64> (e) ).to_ulong();
             }

        }else if (fil_format==Fil_format::Bin) {
            for (unsigned int i = 0; i < heltall_vektor.size(); ++i) {
                char a,b,c;
                fil >> a >> b >> c;
                string e;
                fil >> e;
                heltall_vektor[i]= ( bitset<64> (e) ).to_ulong();

             }

        }
        }

    }

    void heltall_bilde::skriv_ut(){
        for (unsigned int i = 0; i < heltall_vektor.size(); ++i) {
            bitset<64>c (heltall_vektor[i]);
            cout << setw(2)<< i << " - " << c.to_string('_', 'W') << endl;

         }
        cout << "***********************************************************************************************\n";
        cout << "***********************************************************************************************\n";
    }


    void heltall_bilde::setBitenTilEn(unsigned int y, unsigned int x){
        if (x > 0 && x < 64 && y >= 0 && y < 64) {
            unsigned long long tall= 1ull << (x-1);
            heltall_vektor[y] = heltall_vektor[y] | tall;
        }
    }

/**
 * a. 0: Alle elementene nullstilles – som Init
 * b. 1: Første element settes til 1. Alle andre tall blir uforandret.
 * c. \: heltall_vektor[0] settes k-te bit til 1. For heltall_vektor[1] settes
 *      (k+1)-te bit til 1. Og så videre til kanten eller siste tall er nådd.
 * d. /: Som over bare i synkende rekkefølge.
 * e. |: Setter k-te bit lik 1 i alle elementene.
 * f. -: Setter alle bit lik 1 for k-te element.
*/
    void heltall_bilde::lag_bilde(char b){
        int y=0;
        heltall_bilde::lag_bilde(b,y);
    }


    void heltall_bilde::lag_bilde(char b, int y){
//        k=(k<=0 || k>63) ? 0 : k;
        if (y>=0 && y<=63) {

        unsigned long int x = 1;
        switch (b) {
        case '0':
            heltall_vektor.assign(64,0);
            skriv_ut();
            break;
        case '1':
            heltall_vektor[0]=1;
            skriv_ut();
            break;

        case '\\':
            for (unsigned int i = 0; i < 64 && i <= (63-y) ; ++i)
                heltall_vektor[i]= 1ull<<(63-i-y);
            skriv_ut();
            break;

        case '/':
            for (unsigned int i = 0; i < 64 && i <= (63-y); ++i)
                heltall_vektor[i]= 1ull <<(i+y);
            skriv_ut();

            break;
        case '|':
            for (unsigned int i = 0; i < 64; ++i)
                heltall_vektor[i] = x <<y;
            skriv_ut();

            break;
        case '-':
                 heltall_vektor[y]= (1<<63)-1;
                 skriv_ut();

            break;


        default:
            break;
        }
        }


    }

/**    == for å sammenligne to heltall_bilde. Sammenlign størrelse og innhold. Hvis begge er like,
 *     returner true, ellers false*/
    bool heltall_bilde::operator==(heltall_bilde & v2) {
        bool like = heltall_vektor.size() == v2.heltall_vektor.size();

        for (int i = 0; i < 64 && like ; ++i) {
            like = heltall_vektor[i] == v2.heltall_vektor[i];
        }
        return like;
    }

    /** + for å legge sammen to heltall_bilde med bitvis OR (|). Test at lengde er lik og
     * kast et unntak hvis de er ulike.*/
    void heltall_bilde::operator|(heltall_bilde & v2) {
        bool like_langt = heltall_vektor.size() == v2.heltall_vektor.size();

        if (like_langt) {
            for (int i = 0; i < 64 ; ++i) {
                 heltall_vektor[i] = heltall_vektor[i] | v2.heltall_vektor[i];
            }

        }

    }

    /** ~ for å snu alle bits i et heltall_bilde */
    void heltall_bilde::operator~() {
        skriv_ut();
        for (int i = 0; i < 64 ; ++i) {
//            bitset<64> bin = heltall_vektor[i];
//            heltall_vektor[i] =  bin.flip().to_ullong();
            heltall_vektor[i] =  (bitset<64> ( heltall_vektor[i]) ).flip().to_ullong();
        }
        skriv_ut();
    }


