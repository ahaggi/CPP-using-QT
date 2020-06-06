#include <iostream>
#include <cmath>
#include<vector>
#include <iomanip>
#include <algorithm>

using namespace std;

int m =  pow(2 ,8) - 1;
int a =  1103515245;
int b =  12345;


int pseudotilfeldige(int x){
//    X(n+1) = (a*X(n) + b) mod m
    return ( (a*x) + b) % m;
}

int main(int argc, char *argv[])
{
//    std::vector<char> characters;
//    characters.assign(5, 'a');//Lengde 5, alle 'a'
//    vector v1(17);  v1=17	 // 17 elements, each with the value 0
//    vector v2 {17};	 // 1 element with value 17
    vector<int> vektor;
    vektor.push_back(0);
    cout << "Den   0. tall er 0 \n";

    for (int var = 1; var < m; ++var) {
        int y = pseudotilfeldige(vektor.at(var-1));
        vektor.push_back(y);
        cout << "Den "<< setw(3) << var << ". tall er " << y << "\n";
    }


    /** ***************find remove*******************/

        std::vector<int> myvector;

         // set some values (from 1 to 10)
         for (int i=1; i<=10; i++) myvector.push_back(i);

          vector<int>::iterator it = find(myvector.begin(), myvector.end(), 12);
         // erase the it-th element if exists
          if (it!=myvector.end())
              myvector.erase (it);

          it = find_if(myvector.begin(), myvector.end(), [](int a){return a>=9; });
          // erase the it-th element if exists
           if (it!=myvector.end())
               myvector.erase (it);


         // erase the first 3 elements:
         myvector.erase (myvector.begin(),myvector.begin()+3);

         std::cout << "myvector contains:";
         for (unsigned i=0; i<myvector.size(); ++i)
           std::cout << ' ' << myvector[i];
         std::cout << '\n';

    return 0;
}
