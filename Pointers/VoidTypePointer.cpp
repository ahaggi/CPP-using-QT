
#include<iostream>
using namespace std;

int main() {
    int x = 9;
    char ch = 'a';
    void *ptr;
    ptr = &x; // ptr points to address of 'x' i.e holds the address of 'x'
    cout << "Address of 'x' : " << ptr << " and Value of 'x' : " << x << endl;
    cout << "Address of 'x' : " << ptr << " equivalent to    : " << &x << endl;
    ptr = &ch; // ptr now points to address of 'ch'
    cout << "Address of 'ch' : " << ptr << " and Value of 'ch' : " << ch << endl;
    cout << "Address of 'ch' : " << ptr << " equivalent to     : " << &ch << endl;   //OBS KAN IKKE BRUKE &ch ISTEDENFOR ptr

    return 0;
}

/* OBS
 * HVIS ptr PEKER PÅ char-type ==> KAN IKKE FÅ TAK I VARIABELEN-ADRESSE VED Å SKRIVE &ch ISTEDENFOR ptr
 *
 * PGA AT ptr er void-pointer ==> KAN IKKE FÅ TAK I VARIABELEN-VERDI VED Å SKRIVE *ptr ISTEDENFOR x eller ch
 * error: ‘void*’ is not a pointer-to-object type
/*

Output
Address of 'x' : 0x7ffca9b45f14 and Value of 'x' : 9
Address of 'x' : 0x7ffca9b45f14 equivalent to : 0x7ffca9b45f14
Address of 'ch' : 0x7ffca9b45f13 and Value of 'ch' : a
Address of 'ch' : 0x7ffca9b45f13 equivalent to : a 	//OBS KAN IKKE BRUKE &ch ISTEDENFOR ptr
*/
