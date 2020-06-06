#ifndef EDGE_H
#define EDGE_H

class Node;  //forhånd declarering
using namespace std;
class Edge {
public:
    Edge(Node* v, Node* w, int wt = 0, bool d = false);
    ~Edge();
    bool isDirected;
    int weight;
    Node* endpoint[2];

    bool operator ==(Edge *e);
};

Edge::Edge(Node* v, Node* w, int wt, bool d){
    endpoint[0] = v;
    endpoint[1] = w;
    weight = wt;
    isDirected = d;
}
bool Edge::operator ==(Edge *e){
    return ( e->endpoint[0] == this->endpoint[0] && e->endpoint[1] == this->endpoint[1] );
}
Edge::~Edge(){
    cout << "Edge: "<< weight << ", blir slettet"<< endl;

}

#endif // EDGE_H
