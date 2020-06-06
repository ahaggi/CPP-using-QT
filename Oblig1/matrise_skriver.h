#ifndef MATRISE_SKRIVER_H
#define MATRISE_SKRIVER_H
#include <iostream>
#include<bitset>
#include <vector>
#include <cmath>
#include <algorithm>
#include <unistd.h>
#include "util_heltall.h"

using namespace std;

class matrise_skriver
{

public:
    matrise_skriver();

    int finn_neste_pos(vector<util_heltall> v ,int i_plus, int k_pos);
    void lag_kommando_streng(vector<util_heltall> v);

    void skriv_ut_simulering();

    string les_tall_h_mot_v(util_heltall tall);
    string les_tall_v_mot_h(util_heltall tall);
    void skriv_kommando_streng();
    void les_En_kommando_streng(int y, string str, int &x);

    string  utskrift_kommando_streng;
    vector<vector<char>> matrise_simulering;
    void skriv_ut_med_timer(vector<vector<char>> &ms);

};

#endif // MATRISE_SKRIVER_H
