#include <iostream>

using namespace std;
class noe{
public:
//    noe(){ a=1; b=1;} det samme
//    noe(int _a=1,int _b=1){ a=_a ; b=_b;} det samme
    noe(string _navn="a",int _verdi=1): navn(_navn), verdi(_verdi){}
    string navn;
    int verdi;
    ~noe(){
        cout << "Obj-et med navn: " << navn << ", og verdi: " << verdi << ", blir slettet" << endl;
    }


};

int main(int argc, char *argv[])
{  //se graf projektet
    noe n1;
    noe *n4;

    {
        noe n2 ("b" , 2);
        noe *n3 = new noe ("c" , 3);

        n4 = new noe ("d" , 4);

        delete n3;
    }
    delete n4;
    return 0;

  /**
    Obj-et med navn: c, og verdi: 3, blir slettet    innen blokk med keyword delete
    Obj-et med navn: b, og verdi: 2, blir slettet    etter blokk
    Obj-et med navn: d, og verdi: 4, blir slettet    med keyword delete
    Obj-et med navn: a, og verdi: 1, blir slettet    etter return
*/
}
