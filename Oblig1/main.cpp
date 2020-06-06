#include <iostream>
#include<bitset>
#include <cmath>
#include <vector>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <unistd.h>
#include <heltall_bilde.h>
#include <sirkel.h>
#include <util_heltall.h>
#include <fakulitet.h>
#include <matrise_skriver.h>
#include <person.h>
#include <ansattdata.h>

using namespace std;


 int main(int argc, char *argv[])
{
    /** ****************************************************************
     * ******************* fakulitet ***********************************
     * *****************************************************************
    */


//    int n = 13;
//    short int x1 = n;
//    short int f1 =  fakulitet::fakulitet_SHRT(x1);
//    cout << "fakulitet for short verdi"<< x1 <<" er lik " << f1 << endl << "-------------------------------------------"<< endl;

//    unsigned short int x2 = n;
//    unsigned short int f2 =  fakulitet::fakulitet_USHRT(x2);
//    cout << "fakulitet for unsigned short verdi"<< x2 <<" er lik " << f2 << endl << "-------------------------------------------"<<endl;

//    int x3 = n;
//    int f3 =  fakulitet::fakulitet_INT(x3);
//    cout << "fakulitet for int verdi"<< x3 <<" er lik " << f3 << endl << "-------------------------------------------"<<endl;

//    unsigned int x4 = n;
//    unsigned int f4 =  fakulitet::fakulitet_UINT(x4);
//    cout << "fakulitet for unsigned int verdi"<< x4 <<" er lik " << f4 <<endl << "-------------------------------------------"<< endl;

//    long long int x5 = n;
//    long long int f5 =  fakulitet::fakulitet_LNG_ULNG(x5);
//    cout << "fakulitet for long verdi"<< x5 <<" er lik " << f5 << endl << "-------------------------------------------"<<endl;
    /** ********************************************************************************************************************************
     *  *******************************************************************************************************************************/




    /** ****************************************************************
     * ******************* util_heltall ********************************
     * *****************************************************************
    */
//    //18446744073709551616
//    util_heltall u(2305843009213693952-1);

//    cout <<  "u.skrivUt()"<<  u.skrivUt() << endl;
//    cout <<  "u.beregn_antall_enere()"<<  u.beregn_antall_enere() << endl;
//    cout <<  "u.beregn_enere_mindre_enn_k(3)"<<  u.beregn_enere_mindre_enn_k(3) << endl;
//    cout <<  "u.beregn_enere_strr_enn_k(3)"<<  u.beregn_enere_strr_enn_k(3) << endl;
//    cout <<  "u.finn_hoeyeste_signifikante_ener_pos()" <<  u.finn_hoeyeste_signifikante_ener_pos() << endl;
//    cout <<  "u.finn_lengde()" <<  u.finn_lengde() << endl;
//    cout <<  "u.is_palindrome() "<<  u.is_palindrome() << endl;
//    cout <<  "u.les_k_bit(2) "<<  u.les_k_bit(7) << endl;
//    cout <<  "u.speilvend()" <<  u.speilvend() << endl;
//    cout <<  "u.speilvend()" <<  u.speilvend2() << endl;
    /** ********************************************************************************************************************************
     *  *******************************************************************************************************************************/




    /** ****************************************************************
     * ******************* heltall_bilde *******************************
     * *****************************************************************
    */

//    heltall_bilde hl;
//    int k;
//     cout << "tast inn et tall mellom 0 og 63 \n"
//    while (  cin >> k ) {
//      hl.lag_bilde('0',k);
//      hl.lag_bilde('1', k);
//      hl.lag_bilde('/', k);
//      hl.lag_bilde('\\', k);
//      hl.lag_bilde('|', k);
//      hl.lag_bilde('-', k);
//      //      hl.Lagre_bilde("/home/haji/Desktop/QT/Oblig1/null.dat",Fil_format::Bin);
////      hl.Les_bilde("/home/haji/Desktop/QT/Oblig1/null.dat",Fil_format::Bin);
//      hl.skriv_ut();
//    }

/** ****************************************************************
 * ******************* heltall_bilde operator **********************
 * *****************************************************************
*/
//    heltall_bilde heltall_bilde1;
//    heltall_bilde heltall_bilde2;

//    heltall_bilde1.lag_bilde('/', 1);
//    cout << "heltall_bilde1  er ";
//    if (!(heltall_bilde1 == heltall_bilde2)) cout << "ikke ";
//    cout << " lik  heltall_bilde2"  << endl<< endl;

//    heltall_bilde2.lag_bilde('/', 1);
//    cout << "heltall_bilde1  er ";
//    if (!(heltall_bilde1 == heltall_bilde2)) cout << "ikke ";
//    cout << " lik  heltall_bilde2"  << endl<< endl;

//    ~heltall_bilde1;
//    cout << "heltall_bilde1  er ";
//    if (!(heltall_bilde1 == heltall_bilde2)) cout << "ikke ";
//    cout << " lik  heltall_bilde2"  << endl<< endl;




/** ****************************************************************
 * ******************* heltall_bilde og sirkel *********************
 * *****************************************************************
*/
//        heltall_bilde heltall_bilde3;

//        unsigned int r,oY,oX;
//        cout << "Tast inn radius , origoY , origoX \n For å nullstille tegning tast inn 0 3 ganger\n";
//        while (  cin >> r >> oY >> oX ) {
//            if (r>0) {
//                sirkel sirkel(r,oY,oX);
//                sirkel.tegn_sirkel(heltall_bilde3, r , oY ,oX);
//                cout << "Tast inn radius , origoY , origoX \n For å nullstille tegning tast inn 0 3 ganger\n";
//            }else
//                heltall_bilde3.lag_bilde('0');
//        }

    //    /** ****************************************************************
    //     * ******************* heltall_bilde og sirkel *********************
    //     * *****************************************************************
    //*/
    //    matriseskriver ms;
    //    vector<unsigned long int> v = ms.generer_En_Vektor();
    //    ms.fyll_Paa_matrise_og_skriv_ut(v);



////      Generer 64 heltall vektor
//    vector<unsigned long int> v;
//    for (int t = 0; t < 64; ++t) {
//        unsigned long int tall = 1ull << (64 - 2*t );
//         --tall;
//        tall = tall << (t%32);
//        v.push_back(tall);
//        cout << t << "-"<< bitset<64>(tall)<< " "<< (63 - 2*t ) << endl;
//    }

//    int h=0;
//    int v=0;


//    string str ="";
//    for (int ind = 0; ind < 64; ++ind) {
//        str += (bitset<64>(v[ind])).to_string();

//    }

//     vector<vector<char>> v_ch( 64 , vector<char>(64) );

//    for (int y = 0; y < 64; ++y) {

//        v_ch[y].assign(64, ' ');


//        string temp = "";
//        temp = str.substr(64*y, 64); // Hver del-streng representeres et heltall

//        //Ta vare på verdien
//        unsigned long int tall = (bitset<64>(temp)).to_ulong();
//        util_heltall uth(tall);
//        util_heltall not_uth(uth.speilvend());
//        int uth_lengde = uth.finn_hoeyeste_signifikante_ener_pos()+1;
//        int not_uth_lengde = not_uth.finn_hoeyeste_signifikante_ener_pos()+1;



//        if (y%2 == 0){ //OBS kunne skrive kun 1 "x" for-løkke, og sette denne if-setning inn i for-løkken for å beregne x-verdi
//            //v til h
//            uth.set_heltall(uth.speilvend());
//            int heltall_lengde = uth.finn_hoeyeste_signifikante_ener_pos()+1;
//            for (int x = 0; x < 64 ; ++x) {
//                v_ch[y][x] = temp.at(x);
//                if (x >= (64-uth_lengde)  && x < not_uth_lengde ) skrivUt(v_ch);
//            }
//        }
//        else{
//            //h til v
//            int heltall_lengde = uth.finn_hoeyeste_signifikante_ener_pos()+1;
//            for (int x = 63 ; x >= 0; --x) {
//                v_ch[y][x] = temp.at(x);
//                if (x >= (64-uth_lengde)  && x < not_uth_lengde ) skrivUt(v_ch);

//            }
//        }
//    }

    /** ****************************************************************
     * ******************* matriseskriver_heltall *********************
     * *****************************************************************
    */
    vector<util_heltall> v;
    srand(time(0));
    for (int i = 0; i < 64; ++i) {
        unsigned long int t = rand();
        t=t<<10;
        v.push_back(util_heltall(t));
        cout << bitset<64>(t)<< endl;
    }
//    matrise_skriver matriseskriver;
//    matriseskriver.lag_kommando_streng(v);

//    matriseskriver.skriv_kommando_streng();
    /** ****************************************************************/

//    vector<util_heltall> v;
//    heltall_bilde hl;
//    hl.lag_bilde('|', 10);
//    for (int ind = 0; ind < 64; ++ind) {
//        unsigned long int t = hl.heltall_vektor[ind];
//        v.push_back(util_heltall(t));
//    }

//    matrise_skriver matriseskriver;
//    matriseskriver.lag_kommando_streng(v);

//    matriseskriver.skriv_kommando_streng();




     /** ************************************************************************************
      *  *********************************Person og ansatte**********************************
      *  ************************************************************************************
    */

//     Person p1 ("navn1",1,Type::MENTOR);
//     Person p2 ("navn2",2,Type::SUPER_MENTOR);
//     Person p3 ("navn3",3,Type::SUPER_MENTOR);
//     p1.set_tilknyttet(p2);

//     cout<< p1.kan_legge_en_som_mentor(p2)<< endl;
//     cout<< p2.kan_legge_en_som_mentor(p1)<< endl;


//     p1.set_tilknyttet(p3);


//     vector<AnsattData> AnsattData_vektor;
//     for (int i = 0; i < 10; ++i) {
//         // AnsattData a1 ("navn1",1,Type::MENTOR, 1, 1000, 'a');
//         string navn ="navn"+to_string(i);
//         Type type = static_cast<Type>(i%3);
//         char c = (i+97);
//         AnsattData ad (navn , 1 , type , i+1, 1000, c);
//         for (int ij = 0; ij < 3; ++ij) {
//             Person p ("random"+to_string(ij),1,static_cast<Type>(ij%3));
//              ad.get_paarorende().push_back(p);
//         }
//         AnsattData_vektor.push_back(ad);

//     }
//     for (int j = 0; j < AnsattData_vektor.size(); ++j) {
//         AnsattData_vektor[j].skriv_ut();
//     }




    return 0;
}
