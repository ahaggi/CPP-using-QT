#include <iostream>
#include<fstream>
#include<person.h>
using namespace std;



int main(int argc, char *argv[])
{

    person p1;
    person p2(p1);
    p2.navn ="b";

    person p3;
    p3 = p1 + p2;
    person& p4= p1;
    p1.navn ="qq";
    cout << " p1.navn " << p1.navn <<endl;
    cout << " p2.navn " << p2.navn <<endl;
    cout << " p3.navn " << p3.navn <<endl;
    cout << " p4.navn " << p4.navn <<endl;

//    ofstream of("D:\\New.txt");


    person *p10= &p1;
    p1.navn = "ee";
    cout <<" (*p10).navn " <<  (*p10).navn <<endl; // ee

    p10 = new person(p1);
    p1.navn ="rr";
    cout <<" (*p10).navn " <<  (*p10).navn <<endl; // ee

    delete p10;


    try{

        cout << string("abc").substr(10);

    }catch(...){
        try {
            throw ex();
        } catch (ex e) {
            cout << e.what() << endl;
        }
    }

    cout << string("end OK") << endl;

    return 0;
}
