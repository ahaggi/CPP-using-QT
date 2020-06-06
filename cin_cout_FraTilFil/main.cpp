#include <iostream>
#include<vector>
#include <fstream>

using namespace std;

string filNull ="D:\\QTworkSpace\\cin_lesFraFil\\null.txt";
string filEn ="D:\\QTworkSpace\\cin_lesFraFil\\en.txt";
string filPow2 ="D:\\QTworkSpace\\cin_lesFraFil\\pow2.txt";

bool erlik(const vector<unsigned long long> & v1, const vector<unsigned long long> & v2){

    if (v1.size()!=v2.size()) {
        return false;
    }

    for (int i = 0; i < v1.size(); ++i) {
        if (v1[i] != v2[i])
            return false;
    }
    return true;
}


void skriv_vektor(vector<unsigned long long> & v, string filNavn){
    ofstream fil (filNavn);
    for (vector<unsigned long long>::iterator it = v.begin(); it != v.end(); ++it) {
        fil << *it << endl;
    }
}


int main(int argc, char *argv[])
{

    vector<unsigned long long> kontroll;
    vector<unsigned long long> sammenlign;

    kontroll.assign(64,0);
    skriv_vektor(kontroll,filNull);

    kontroll.at(0)=1;
    skriv_vektor(kontroll,filEn);

    for (unsigned int i = 1; i < kontroll.size(); ++i)
        kontroll[i]=kontroll[i-1]*2;

    skriv_vektor(kontroll,filPow2);






    kontroll.assign(64,0);
    ifstream lesFraFil{filNull};
    unsigned long long tall;
    while (lesFraFil>>tall)
        sammenlign.push_back(tall);

    cout << "er null vektorer like?" << erlik(sammenlign,kontroll)<< endl;

    kontroll[0]=1;
    ifstream lesFraFil2{filEn};
    for (unsigned int i = 0; i < 64; ++i)
        lesFraFil2 >> sammenlign[i];

    cout << "er \"kun en\" vektorer like?" << erlik(sammenlign,kontroll)<< endl;


    ifstream lesFraFil3{filPow2};
    for (unsigned int i = 0; i < 64; ++i){
        kontroll[i] = (i==0) ? 1 :kontroll[i-1]*2;
        lesFraFil3 >> sammenlign[i];
    }
    cout << "er Pow2 vektorer like?" << erlik(sammenlign,kontroll)<< endl;



    return 0;
}

