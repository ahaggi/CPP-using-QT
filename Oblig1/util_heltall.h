#ifndef util_heltall_H
#define util_heltall_H


#include <iostream>
#include<bitset>
#include <cmath>

using namespace std;

 class util_heltall{
private:
    unsigned long  int heltall;

public:
    util_heltall(unsigned long int t);

    unsigned long int get_heltall();
    void set_heltall(unsigned long int t);
    string skrivUt ();

/** a) Lag en funksjon som returner bitverdien i posisjon k. Kast et unntak hvis k er utenfor gyldig område.*/
unsigned int les_k_bit(unsigned int pos);

/** b) Lag en funksjon som returner antall bit til n.*/
unsigned int finn_lengde();

/** c) Lag en funksjon for å beregne antall bit som er satt til 1 i den binære representasjonen for n.*/
unsigned int beregn_antall_enere();
unsigned int beregn_antall_enere(unsigned long h);

/** d) Lag en funksjon for å finne høyeste bit som er satt til 1 i den binære representasjonen for n.
 * Kast ett unntak (exception) hvis tallet er 0*/
int finn_hoeyeste_signifikante_ener_pos();

/** e) Lag en funksjon for å speilvende bitmønsteret til n.*/
unsigned long int speilvend ( );
unsigned long int speilvend2 ( );

/** f) Lag en funksjon som returnerer true hvis n er symmetrisk i bitmønsteret, ellers false.*/
bool is_palindrome();

/** g) Lag en funksjon som finner antall bit satt til 1 i posisjon mindre enn et heltall k (til høyre).
 * Kast et unntak hvis k er utenfor gyldig område.*/
unsigned int beregn_enere_mindre_enn_k (unsigned int pos);



/** h) Lag en funksjon som finner antall bit satt til 1 i posisjon større enn et heltall k (til venstre).
 * Kast et unntak hvis k er utenfor gyldig område.*/
unsigned int beregn_enere_strr_enn_k ( unsigned int pos);

};


#endif // util_heltall_H
