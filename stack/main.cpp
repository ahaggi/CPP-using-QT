#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;

class node {
public:
    node(int v, node *f){
        forrigje=f;
        verdi=v;
    }
    node *forrigje;
    int verdi;

};

int main(int argc, char *argv[])
{
    vector<node*> v1;
    node *forrigje= NULL;
    for (int var = 0; var < 10; ++var) {
        node * p = new node(var,forrigje);  //OBS uten new vil alle elementer i vektoren referere til det samme instanse
        v1.push_back(p);
        forrigje=p;
    }

    for (vector<node*>::iterator it = v1.begin(); it!=v1.end();  ++it) {
        cout << (**it).verdi << endl;
    }

/** ***************************************************************/
    int myints[] = {10,20,30,5,15};
   std::vector<int> v(myints,myints+5);
   auto lmp = [](int i , int j){return i<j;};
   std::make_heap (v.begin(),v.end(),lmp);// max heap
   std::cout << "initial max heap   : " << v.front() << '\n';

   std::pop_heap (v.begin(),v.end(),lmp); //pop fjerner ikke rot elem, men setter rot som den siste
   v.pop_back();
   std::cout << "max heap after pop : " << v.front() << '\n';

   v.push_back(99);
   std::push_heap (v.begin(),v.end(), lmp);//posh fjerner ikke rot elem, men setter rot som den første
   std::cout << "max heap after push: " << v.front() << '\n';

   std::sort_heap (v.begin(),v.end(), lmp);//lager ordnet liste, også(min==>maks)

   std::cout << "final sorted range :";
   for (unsigned i=0; i<v.size(); i++)
     std::cout << ' ' << v[i];

   std::cout << '\n';
/** ***********************************************************************/

    return 0;
}
