#include <iostream>
#include "graph.h"
#include "priorityqueue.h"

using namespace std;

std::ostream& operator<<(std::ostream& os, const Edge* e){
    os << "(" << e->endpoint[0]->data << ", " <<  e->endpoint[1]->data << ")";
    return os;
}

std::ostream& operator<<(std::ostream& os, const Node* n){
    char previous = ' ';
    if(n->previous != NULL)
            previous = n->previous->data;
    os << "(" << n->data << ", " <<  n->distance << ", " << previous << ")";
    return os;
}

template <typename T>
void printVector(const vector<T>& v){
    for(typename vector<T>::const_iterator it = v.begin(); it != v.end(); it++)
        cout << *it << endl;
}

int main()
{
    Graph graf;
    Node* a = new Node('a');
    Node* b = new Node('b');
    Node* c = new Node('c');
    Node* d = new Node('d');
    Node* e = new Node('e');
    Node* f = new Node('f');

    graf.insertVertex(a);
    graf.insertVertex(b);
    graf.insertVertex(c);
    graf.insertVertex(d);
    graf.insertVertex(e);
    graf.insertVertex(f);
    graf.insertEdge(a,b,1);
    graf.insertEdge(b,c,2);
    graf.insertEdge(b,d,3);
    graf.insertEdge(c,e,4);
    graf.insertEdge(d,e,5);
    graf.insertEdge(e,f,1);


    cout << "priorityqueue" << endl;
    priorityqueue pq;
    pq.add(new Edge(a,b,1));
    pq.add(new Edge(d,e,5));
    pq.add(new Edge(b,c,2));
    pq.add(new Edge(c,e,4));
    pq.add(new Edge(e,f,1));
    pq.add(new Edge(b,d,3));

    while(!pq.is_empty()){
        cout << pq.remove1()->weight << endl;
    }
    cout << "******************************" << endl;
    cout << "******************************" << endl;
    cout << "vertices" << endl;
    printVector(graf.vertices());

//    graf.removeVertex(b);
    cout << "******************************" << endl;
    cout << "Depth First Traversal" << endl;
    graf.depthFirstTraversal(f);

    cout << "******************************" << endl;
    cout << "breadthFirstTraversal" << endl;
    graf.breadthFirstTraversal(f);

    cout << "******************************" << endl;
    cout << "primsAlgorithm" << endl;
    vector<Edge*> v = graf.primsAlgorithm();
    printVector(v);

    cout << "******************************" << endl;
    cout << "Nesten_KruskalAlgorithm" << endl;
    vector<Edge*> v1 = graf.Nesten_KruskalAlgorithm();
    printVector(v1);

    cout << "******************************" << endl;
    cout << "dijkstrasAlgorithm" << endl;
    graf.dijkstrasAlgorithm(e);
    printVector(graf.vertices());

    cout << "******************************" << endl;
    cout << "approxVertexCover" << endl;
    printVector(graf.approxVertexCover());

    cout << "******************************" << endl;
    cout << "checkVertexCover" << endl;
    cout << graf.checkVertexCover(graf.approxVertexCover()) << endl;


    Graph graf2;

    Node* s_ = new Node('s');
    Node* a_ = new Node('a');
    Node* c_ = new Node('c');
    Node* b_ = new Node('b');
    Node* d_ = new Node('d');
    Node* t_ = new Node('t');

    graf2.insertVertex(s_);
    graf2.insertVertex(a_);
    graf2.insertVertex(c_);
    graf2.insertVertex(b_);
    graf2.insertVertex(d_);
    graf2.insertVertex(t_);

    graf2.insertEdge(s_,a_,7);
    graf2.insertEdge(s_,c_,8);
    graf2.insertEdge(a_,c_,3);
    graf2.insertEdge(a_,b_,6);
    graf2.insertEdge(c_,d_,3);
    graf2.insertEdge(c_,b_,4);
    graf2.insertEdge(b_,d_,2);
    graf2.insertEdge(b_,t_,5);
    graf2.insertEdge(d_,t_,2);


    cout << "******************************" << endl;
    graf.nullstillAlleDistance();
    cout << "dijkstrasAlgorithm" << endl;
    graf.dijkstrasAlgorithm(a);
    printVector(graf.vertices());
    cout << "******************************" << endl;
    graf.nullstillAlleDistance();
    cout << "dijkstrasAlgorithm" << endl;
    graf.dijkstrasAlgorithm2(a);
    printVector(graf.vertices());
    cout << "******************************" << endl;
    graf.nullstillAlleDistance();
    cout << "dijkstrasAlgorithm" << endl;
    graf2.dijkstrasAlgorithm(s_);
    printVector(graf2.vertices());
    cout << "******************************" << endl;
    graf.nullstillAlleDistance();
    cout << "dijkstrasAlgorithm" << endl;
    graf2.dijkstrasAlgorithm2(s_);
    printVector(graf2.vertices());

    return 0;
}

