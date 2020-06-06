#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include <edge.h>
#include <node.h>
#include <algorithm>
#include <functional>

using namespace std;

//1.The data type of the elements in the collection should be the Edge class as specified in
//the code from lecture 17.
//2.The priority rule should be that the lower edge weight, the higher priority.
//3.The class should have the operations "add" and "remove" that respectively adds a new
//element and removes the element with highest priority.
//The class should also have an operation "isEmpty" that returns true if the queue is
//empty and false otherwise.

class priorityqueue{
public:
    priorityqueue();
    ~priorityqueue();
    void add(Edge* ny);
    Edge *remove1();
    vector<Edge*> liste;
    bool is_empty();
    void operator +=(Edge * ny);
};

priorityqueue::priorityqueue(){

}

void priorityqueue::add(Edge *ny){
    vector<Edge*>::iterator it = find_if(liste.begin(), liste.end(), [ny](Edge* e){return ny->weight >= e->weight; });
    if (it == liste.end()) {
        // i tilfelle #liste# er ikke tom ,, alle elementene er mindre enn e
        liste.push_back(ny);
    }else{
        liste.insert(it , ny);
    }
}

Edge* priorityqueue::remove1(){
        Edge * e = liste.back();
        liste.pop_back();

        return e;
}



//    int ind = -1;
//    while (it!= liste.end() && ! samme_edge((*it), E) ) {
//        ++ind; //neste
//    }
//    // enten funnet eller it == end
//    if (ind != -1){
//        //Å fjerner denne edgen fra koblte noder kanskje er nødvendig
//        liste.earse(liste.begin()+ind);

//    }
//        remove(liste.begin(), liste.end(), it); OBS remove ville fjerne alle Edge som er lik "*it", dvs fjerne alle duplikater
//        1,2,3,2,2,4==> remove (liste.begin(), liste.end(), 2) ==> 1,3,4




bool priorityqueue::is_empty(){
    return liste.begin() == liste.end();
}


void priorityqueue::operator +=(Edge *ny){
    add(ny);
}

priorityqueue::~priorityqueue(){

}



#endif // PRIORITYQUEUE_H
