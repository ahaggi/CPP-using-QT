#ifndef NODE_H
#define NODE_H
#include <vector>
#include <algorithm>
#include<climits>
#include<cstdlib>
#include "edge.h"
using namespace std;
static int NodeId=0;

class Node {
public:
    Node(int d) : data(d), visited(false), distance(INT_MAX), previous(NULL){id=++NodeId;}
    ~Node();
    int id;
    char data;
    bool visited;
    int distance;
    Node* previous;
    std::vector<Edge*> edgeList;
    bool operator ==(Node *n);
    void removeIncidentEdge(Edge *e);

};

bool Node::operator ==(Node *n){
    return (n->id ==this->id);
}

void Node::removeIncidentEdge(Edge *e){

    vector<Edge*>::iterator edge_it = find(edgeList.begin() , edgeList.end() , e);
    edgeList.erase(edge_it);
}

Node::~Node(){
    cout << "Node: "<< data << ", blir slettet"<< endl;
}

#endif // NODE_H
