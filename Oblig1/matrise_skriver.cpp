#include "matrise_skriver.h"

matrise_skriver::matrise_skriver(){
    matrise_simulering.assign( 64 , vector<char>(64) );
    utskrift_kommando_streng ="";
}
string matrise_skriver::les_tall_h_mot_v(util_heltall tall){
    string str = "";
    int antall_ener = 0;
    int antall_nuller = 0;
    int k = 0;
    while (k<64) {
        while ( k<64 && tall.les_k_bit(k) ) {
            antall_nuller=0;
            ++antall_ener;
            ++k;
        }
        if (antall_ener!=0 && tall.beregn_enere_strr_enn_k(k-1)) {
            str+="(.-1)"+ to_string(antall_ener) +" ";
        }
        else if (antall_ener>1 && !tall.beregn_enere_strr_enn_k(k-1)  ) {
            str+="(.-1)"+ to_string(antall_ener-1) +" (.)1" +" ";

        }else if (antall_ener==1 && !tall.beregn_enere_strr_enn_k(k-1)  ) {
            str+="(.)1 ";
        }

        while (k<64 && (!tall.les_k_bit(k))) {
             antall_ener=0;
            ++antall_nuller;
            ++k;
        }
        str+=(str=="" || k>=64 || k<0 ||!tall.beregn_enere_strr_enn_k(k-1)) ? "" : "(-1)"+ to_string(antall_nuller) +" ";
    }
    return str;
}
string matrise_skriver::les_tall_v_mot_h(util_heltall tall){
    util_heltall not_tall (tall.speilvend());
     string str = "";
    int antall_ener = 0;
    int antall_nuller = 0;
    int k = 0;
    while (k<64) {
        while ( k<64 && not_tall.les_k_bit(k) ) {
            antall_nuller=0;
            ++antall_ener;
            ++k;
        }
        if (antall_ener!=0 && not_tall.beregn_enere_strr_enn_k(k-1)) {
            str+="(.1)"+ to_string(antall_ener) +" ";
        }
        else if (antall_ener>1 && !not_tall.beregn_enere_strr_enn_k(k-1)  ) {
            str+="(.1)"+ to_string(antall_ener-1) +" (.)1" +" ";

        }else if (antall_ener==1 && !not_tall.beregn_enere_strr_enn_k(k-1)  ) {
            str+="(.)1 ";
        }

        while (k<64 && (!not_tall.les_k_bit(k))) {
             antall_ener=0;
            ++antall_nuller;
            ++k;
        }
        str+=(str=="" || k>=64 || k<0 ||!not_tall.beregn_enere_strr_enn_k(k-1)) ? "" : "(1)"+ to_string(antall_nuller) +" ";
    }
    return str;
}

void matrise_skriver::lag_kommando_streng(vector<util_heltall> v){

    unsigned int k_pos=0;

    for (int i = 0; i < v.size(); ++i) {

    if (v[i].get_heltall() != 0) {
        util_heltall heltall=v[i];
        util_heltall invrt_heltall(heltall.speilvend());

        int heltall_lengde = heltall.finn_hoeyeste_signifikante_ener_pos();
        int  invrt_heltall_lengde = invrt_heltall.finn_hoeyeste_signifikante_ener_pos();

        int mest_s_e = heltall_lengde;
        int minst_s_e = 63 - invrt_heltall_lengde;

         if (i==0 && k_pos < minst_s_e) {
            int steg = minst_s_e-k_pos ;
            utskrift_kommando_streng = utskrift_kommando_streng +  "(-1)" + to_string(steg) +" ";
             k_pos = minst_s_e;
        }
        if (i%2 == 0) {
            int steg = k_pos - mest_s_e;
            utskrift_kommando_streng = utskrift_kommando_streng +  les_tall_h_mot_v(heltall);
             k_pos = mest_s_e;
        }else{
            int steg = k_pos - minst_s_e;
            utskrift_kommando_streng = utskrift_kommando_streng +  les_tall_v_mot_h(heltall);
             k_pos = minst_s_e;
        }


        if (i+1 < v.size()){
            k_pos = finn_neste_pos(v,i+1, k_pos);
        }else{
            utskrift_kommando_streng = utskrift_kommando_streng + "(1)" + to_string(k_pos+1) + " V1 \n" ;
            cout << utskrift_kommando_streng << "\n\n\n";
            k_pos = 0;
        }

    }else{ // v[i].get_heltall() == 0
        k_pos = finn_neste_pos(v,i+1, k_pos);
    }

    }// end for

}

int  matrise_skriver::finn_neste_pos(vector<util_heltall> v ,int i_plus, int k_pos){

    util_heltall uth = v[i_plus];
    if ( uth.get_heltall() != 0 ) {

        util_heltall not_uth=uth.speilvend();

        int uth_lengde = uth.finn_hoeyeste_signifikante_ener_pos();
        int not_uth_lengde = not_uth.finn_hoeyeste_signifikante_ener_pos();

        int mest_s_e = uth_lengde;
        int minst_s_e = 63 - not_uth_lengde;

        if (i_plus%2 == 0) {
            if (k_pos > minst_s_e) {
                utskrift_kommando_streng = utskrift_kommando_streng + "V1 \n[1]" + to_string(abs(minst_s_e - k_pos))+ " " ;
                k_pos = minst_s_e;

            }else if(k_pos < minst_s_e){
                utskrift_kommando_streng = utskrift_kommando_streng +  "V1 \n[-1]" + to_string(abs(minst_s_e - k_pos)) + " ";
                k_pos = minst_s_e;

            }else{// minst er lik k_pos
                utskrift_kommando_streng = utskrift_kommando_streng + "V1 \n";
            }
        }else{
            if (k_pos > mest_s_e) {
                utskrift_kommando_streng = utskrift_kommando_streng +  "V1 \n[1]" + to_string(abs(mest_s_e - k_pos)) + " ";
                k_pos = mest_s_e;

            }else if(k_pos < mest_s_e){
                 utskrift_kommando_streng = utskrift_kommando_streng +  "V1 \n[-1]" + to_string(abs(mest_s_e - k_pos)) + " ";
                k_pos = mest_s_e;

            }else{// mest_s_e er lik k_pos
                utskrift_kommando_streng = utskrift_kommando_streng +"V1 \n";
            }

        }// end else i_plus % 2 != 0

    }else{// hvis neste tall er lik = 0
        k_pos = finn_neste_pos(v,i_plus+1, k_pos);
    }
return  k_pos;
}

void matrise_skriver::skriv_kommando_streng(){
    int i = 0;
    int y=0;
    int pos=63;
    while (i< utskrift_kommando_streng.size()) {
        string str ="";
        while (utskrift_kommando_streng[i]!='\n' && i< utskrift_kommando_streng.size()) {
           str+= utskrift_kommando_streng[i];
           ++i;
        }
        les_En_kommando_streng(y,str,pos);
        ++y;

        ++i; // skip end of line

    }

}

void matrise_skriver::les_En_kommando_streng(int y, string str, int &x ){
    matrise_simulering[y].assign(64,' ');
    int i = 0;
      while (str[i]!='V'&& i < str.size()){
        int verdi_inni_p = 0;
        int verdi_it = 0;

        string temp_inni_p ="";
        string temp_it ="";

        char c = '.';

        while (i < str.size() && !(str.at(i)==')'||str.at(i)==']') ){
            temp_inni_p += str[i];
            ++i;
        }
        int innhold = temp_inni_p.find(".");
        replace(temp_inni_p.begin() , temp_inni_p.end() , '(' , ' ' );
        replace(temp_inni_p.begin() , temp_inni_p.end() , '[' , ' ' );
        replace(temp_inni_p.begin() , temp_inni_p.end() , '.' , ' ' );
        verdi_inni_p = atoi(temp_inni_p.c_str());// .c_str() for å unngå ==> error: cannot convert string to ‘const char*’

        while(str[i]!=' '){
            temp_it+=str[i];
            ++i;
        }
        replace(temp_it.begin() , temp_it.end() , ')' , ' ' );
        replace(temp_it.begin() , temp_it.end() , ']' , ' ' );
        verdi_it = atoi(temp_it.c_str()); // .c_str() for å unngå ==> error: cannot convert string to ‘const char*’


        if (verdi_inni_p < 0){
            c=( innhold >= 0)?'.':'<';

            for (int var = 0; var < verdi_it; ++var) {
                matrise_simulering[y][x]=c;
                skriv_ut_med_timer(matrise_simulering);
                --x;
            }

         } else if (verdi_inni_p > 0){
            c=( innhold >= 0)?'.':'>';

            for (int var = 0; var < verdi_it; ++var) {
                 matrise_simulering[y][x]=c;
                 skriv_ut_med_timer(matrise_simulering);
                ++x;
            }

        } else if (verdi_inni_p == 0){
            c='.';
            matrise_simulering[y][x]=c;
            skriv_ut_med_timer(matrise_simulering);
        }



        ++i;
    }
 }

void matrise_skriver::skriv_ut_med_timer(vector<vector<char>> &ms){

    for (int i = 0; i < ms.size(); ++i) {

    for (int j = 0; j < ms[i].size(); ++j) {
            cout << ms[i][j] << " ";
        }
        cout << endl;
    }
    usleep(100000); // mikrosec 1 / 1 000 000 sec
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;

}












