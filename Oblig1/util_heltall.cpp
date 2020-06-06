



#include "util_heltall.h"

using namespace std;


    util_heltall::util_heltall(unsigned long int t) {
        set_heltall(t);
    }

    unsigned long int util_heltall::get_heltall(){
        return heltall;
    }
    void util_heltall::set_heltall(unsigned long int t){
        heltall = t;
     }
    string util_heltall::skrivUt (){
//        cout << heltall << endl;
        return (bitset<64>(heltall)).to_string();
    }

/** a) Lag en funksjon som returner bitverdien i posisjon k. Kast et unntak hvis k er utenfor gyldig område.*/
unsigned int util_heltall::les_k_bit(unsigned int pos){  //OBS pos starter fra
   unsigned long int tall =heltall;
    if (pos > 63 || pos < 0) {
        cout << " feil pos verdi " << endl;
        return 0;
    }
    tall = tall >> pos;
    return tall & 1;
}
/** b) Lag en funksjon som returner antall bit til n.*/
unsigned int util_heltall::finn_lengde(){

    return sizeof(heltall);

}

/** c) Lag en funksjon for å beregne antall bit som er satt til 1 i den binære representasjonen for n.*/
unsigned int util_heltall::beregn_antall_enere(){
    unsigned long int h = heltall;
   unsigned int teller=0;
    while (h!=0) {
        teller= (h%2!=0)?teller+1:teller;
        h=h/2;
    }
    return teller;
}
unsigned int util_heltall::beregn_antall_enere(unsigned long int h){
   unsigned int teller=0;
    while (h!=0) {
        teller= (h%2!=0)?teller+1:teller;
        h=h/2;
    }
    return teller;
}
/** d) Lag en funksjon for å finne høyeste bit som er satt til 1 i den binære representasjonen for n.
 * Kast ett unntak (exception) hvis tallet er 0*/
int util_heltall::finn_hoeyeste_signifikante_ener_pos(){
    if (heltall == 0)
        cout << "skulle kaste unntak \n" ;
     //alternativt
    int res =0;
    unsigned long int n = heltall;
    while (n){
       n=n>>1;
       res++;
    }
    --res;
    return  res ;
}

/** e) Lag en funksjon for å speilvende bitmønsteret til n.*/

unsigned long int util_heltall::speilvend ( ){
    unsigned long int tall =heltall;

    string str2 = (bitset<64>(tall)).to_string();
    string res="";
    for (int var = str2.length()-1; var >=0; --var) {
        res.push_back(str2.at(var));
    }
//    cout << res << endl;
    unsigned long int not_tall = (bitset<64>(res)).to_ulong();
    return not_tall;
}
unsigned long int util_heltall::speilvend2 ( ){
   unsigned long int tall = heltall;
   unsigned long int lengde = finn_hoeyeste_signifikante_ener_pos()+1;
   unsigned long int not_a = 1ull << (lengde );
   unsigned long int res = tall ^ not_a;
    return res;
}

/** f) Lag en funksjon som returnerer true hvis n er symmetrisk i bitmønsteret, ellers false.*/
bool util_heltall::is_palindrome()
{
    unsigned long int tall = speilvend() ;
    string s = (bitset<64>(tall)).to_string() ;  // OBS må lese tallet omvendt slik at last og first passes
    int first = 0;            // index of first letter
    int last = finn_hoeyeste_signifikante_ener_pos();  // index of last letter
    while (first < last) {    // we haven't reached the middle
        if (s.at(first)!=s.at(last))
            return false;
        ++first;              // move forward
        --last;               // move backwards
    }
    return true;
}

/** g) Lag en funksjon som finner antall bit satt til 1 i posisjon mindre enn et heltall k (til høyre).
 * Kast et unntak hvis k er utenfor gyldig område.*/
unsigned int util_heltall::beregn_enere_mindre_enn_k (unsigned int pos){
//    pos = pos; // pos starter fra 0 ...
    unsigned long int tall = heltall;
    if (pos <= 0 || pos > 63) {
//        cout <<"pos=" << pos << ", skulle kaste unntak skulle kaste unntak  pos er større enn tall-lengde " << endl;
        return 0;
    }
    tall = tall << (64-pos);
//    cout << "    qqqqqqqqqq       " << bitset<64>(tall) << endl;

    return beregn_antall_enere(tall);
}



/** h) Lag en funksjon som finner antall bit satt til 1 i posisjon større enn et heltall k (til venstre).
 * Kast et unntak hvis k er utenfor gyldig område.*/
unsigned int util_heltall::beregn_enere_strr_enn_k ( unsigned int pos){
    unsigned long int tall =heltall;
    pos = pos+1; // pos+1 pga at pos starter fra 0
    if (pos < 0 || pos > 63) {
//        cout <<"pos=" << pos << ",skulle kaste unntak skulle kaste unntak  pos er større enn tall-lengde " << endl;
        return 0;
    }
    tall = tall>>pos;
//    cout << "    qqqqqqqqqq       " << bitset<64>(tall) << endl;

    return beregn_antall_enere(tall);
}

