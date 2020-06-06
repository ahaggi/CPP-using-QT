#include <iostream>
#include <spelar.h>
#include <vector>
#include <ctime>
#include <algorithm>

using namespace std;

class finnMaks{
public:
    bool operator()(spelar s1, spelar s2){
        return s1>s2;
    }
};

int main(int argc, char *argv[])
{
    vector<spelar> spelare;

    srand(time(NULL));
    for (int i = 0; i < 10; ++i) {
        int p = rand()%100 ;
        spelar s;
        spelare.push_back(spelar(to_string(i), rand()%100));
    }

    for (vector<spelar>::iterator it = spelare.begin(); it != spelare.end(); ++it) {
        cout << (*it) << endl;
    }

    finnMaks fm;
    vector<spelar>::iterator maks = max_element( spelare.begin(), spelare.end() , fm);
    cout << (*maks).finnPoeng()<< endl;

    return 0;
}
