#include <iostream>

using namespace std;

int f1(int x){ // for en kopi av x value
    return ++x;
}
int f2(int & x){ // for en adresse til 'x'
    return ++x;
}

int f3(const int & x){  // for en adresse til 'x', men denne variable er constant

//  return ++x; error: increment of read-only reference ‘x’
    int xx=x;
    return ++xx;
}

int f4(int *x){
    return ++(*x);
}

int main(int argc, char *argv[])
{

    int x = 1;

    cout << "kall på f1 func. " << f1(x) << endl;
    cout << "kall på f1 func. " << f1(x) << endl;
    cout << "kall på f1 func. " << f1(x) << endl;
    cout << "x verdi blir uendret " << x << endl;

    cout << "kall på f4 med ref args " << f4(&x)<< endl;

    int y = 1;
    cout << "kall på f2 func. " << f2(y) << endl; // 2
    cout << "kall på f2 func. " << f2(y) << endl;// 3
    cout << "y verdi blir " << y << endl; // 3

    cout << "kall på f3 func. " << f3(y) << endl; // 4

    cout << "y verdi blir uendret " << y << endl; // 3
/*

int i = 7;
int & r = i;
r = 9;
// i becomes 9
cr
const int& cr = i;
// cr = 7;
// error: cr refers to const
i = 8;
cout << cr << endl; // write out the value of i (that ’s 8 )

*/
    return 0;
}
