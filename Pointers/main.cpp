//#include <iostream>

//using namespace std;
//int noe (int * i){
//    cout << i;
//}

//int main(int argc, char *argv[])
//{
//    int ii =10;
//    noe(&ii);
// /** *************************** Pointers and references *******************************/
//    int x = 7;
//    int & r = x;
//    r = 10;
//    cout << "x verdi er lik r verdi er lik " << x;
//    /** ******************************************************************/

//    int firstvalue = 5, secondvalue = 15;
//    int * p1, * p2;

//    p1 = &firstvalue;  // p1 = address of firstvalue
//    p2 = &secondvalue; // p2 = address of secondvalue
//    *p1 = 10;          // value pointed to by p1 = 10
//    *p2 = *p1;         // value pointed to by p2 = value pointed to by p1
//    p1 = p2;           // p1 = p2 (value of pointer is copied) "p1 og p2 peker på det samme variable/objekt"
//    *p1 = 20;          // value pointed to by p1 = 20

//    cout << "firstvalue is " << firstvalue << '\n';
//    cout << "secondvalue is " << secondvalue << '\n'<< '\n'<< '\n';
///*
// Itillegg til disse eksampeler, les mer om
// Pointer Arithmetic
// Function Pointers
// NULL Pointer
//*/


//    /** http://www.cplusplus.com/doc/tutorial/pointers/
//     * array og pointers
//     */
//    int a[4] = {1, 2, 3, 4};

////  int* p = &a[2]; denne linjen gir den samme mening som de 2 neste linjene
//    int * p = a;
//    p=p+2;  // beveg pekeren 2 steg fram, men p[2] eller (2)[p] er lik p.neste.neste uten å forandre på pekeren.
////    a++; OBS det blir feil med kun tabel
//    std::cout <<"p peker på : "<< *p <<   '\n';

//    std::cout << "p-neste er "<< p[1]<< '\n';
//    std::cout << "p-neste er "<< 1[p] << '\n';
//    std::cout << "p-neste er "<< *(p+1) << '\n';

//    std::cout << "p-forrigje-forrigje er " << p[-2] << '\n';
//    std::cout << "p-forrigje-forrigje er " << (-2)[p] << '\n';
//    std::cout << "p-forrigje-forrigje er "<< *(p-2) << '\n';

//    std::cout << "p-forrigje er " << p[-1] << '\n';
//    std::cout << "p-forrigje er " << (-1)[p] << '\n';
//    std::cout << "p-forrigje er "<< *(p-1) << '\n';


///*******************************************************************/


////    int numbers[5];
////    int * p;
////    p = numbers;  *p = 10;
////    p++;  *p = 20;
////    p = &numbers[2];  *p = 30;
////    p = numbers + 3;  *p = 40;
////    p = numbers;  *(p+4) = 50;
////    for (int n=0; n<5; n++)
////      cout << numbers[n] << ", ";

//    return 0;
//}


/*  The arrow operator (->)

struct movies_t {
  string title;
  int year;
};

movies_t amovie;
movies_t * pmovie;

pmovie = &amovie;
pmovie->title   equivalent to (*pmovie).title

Here amovie is an object of structure type movies_t, and pmovie is a pointer to point to objects of structure type movies_t.
Therefore, the following code would also be valid:

The arrow operator (->) is a dereference operator that is used exclusively with pointers to objects that have members.
This operator serves to access the member of an object directly from its address

OBS
Both expressions, pmovie->title and (*pmovie).title are valid, and both access the member title of the data structure pointed by
a pointer called pmovie. It is definitely something different than:

*pmovie.title   which is rather equivalent to:   *(pmovie.title)

This would access the value pointed by a hypothetical pointer member called title of the structure object pmovie
(which is not the case, since title is not a pointer type). The following panel summarizes possible combinations of
the operators for pointers and for structure members:

w*/

