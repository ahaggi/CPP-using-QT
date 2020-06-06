#include <iostream>
#include<thread>

using namespace std;
int a =5;

void skrvUt (){
    cout << "Tråd id " << this_thread::get_id() <<endl; //obs get_id
    a=10;

}

void vent (int venteTid){
    chrono::milliseconds duration (venteTid); //kast int  til ms
      cout<< "Start waiting ... " << endl;
      cout << "Tråd id " << this_thread::get_id() <<endl; //obs get_id
//      int x = this_thread::get_id;
}

int main(int argc, char *argv[])
{
    int b=0;
    /* må skriv  oppsettet i .pro filen
     * QMAKE_CXXFLAGS += -std=c++0x -pthread
     * LIBS += -pthread
    */
    thread t(skrvUt);
    t.join();// så main ikke avsluttes mens t kjører
    int a = 7;

//    thread t2([](){a=11;}); //'a' is not captured a!=11
//    thread t2([a](){a=11;}); //read only  a!=11
//    thread t2([=](){a=11;}); //read only  a!=11
    thread t2([&a](){a=11;}); //a=11

//        bruk enten t.join();
//        eller
//        t.detach();// så main kan avsluttes mens t kjører

        t2.join();
        cout << "a = " << a << endl; // siden a ikke sync., så vet vi ikke hvilke a verdi har vi (7 eller 10)

        thread t3(vent, 3000);
        t3.join();

    return 0;
}
