#include <iostream>
#include <vector>
#include <algorithm>
#include "spelar.h"

using namespace std;

class MindreEnn {
public:
    bool operator()(Spelar s1, Spelar s2) const {
        return s1 < s2;
    }
};

ostream& operator<<(ostream& os, const Spelar& s){
    os << s.finnNamn()  << " : " << s.finnPoeng();
    return os;
}

int main()
{
    vector<Spelar> arkiv;
    for (int var = 0; var < 10; ++var) {
       arkiv.push_back(Spelar("test" + to_string(var), 10-var));
    }

    vector<Spelar>::iterator it;
    for(it = arkiv.begin(); it != arkiv.end(); it++){
        cout << (*it) << endl;
    }

    it = max_element(arkiv.begin(), arkiv.end(), MindreEnn());

    cout << (*it) << endl;

    auto lambdaFunc = [](const Spelar s1, const Spelar s2){
        return s1 < s2;
    };

    it = max_element(arkiv.begin(), arkiv.end(), lambdaFunc);

    cout << (*it) << endl;

    it = max_element(arkiv.begin(), arkiv.end(), [](Spelar s1, Spelar s2){
            return s1 < s2;
        });

    cout << (*it) << endl;

    return 0;
}

