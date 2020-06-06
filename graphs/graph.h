#ifndef GRAPH_H
#define GRAPH_H

#include "graphadt.h"
#include "priorityqueue.h"
#include <stack>
#include <queue>
#include <algorithm>
#include <functional>
using namespace std;
class Graph : public GraphADT {

public:
    ~Graph();
    // General graph methods
    Node* rot_Vertex();
    void insertVertex(Node* n);
    void insertEdge(Node* v, Node* w, int i = 0);
    void removeVertex(Node* n);
    void removeEdge(Edge *e);
    vector<Edge*>& incidentEdges(Node* n);
    Node** endVertices(Edge* e);
    Node* opposite(Node* n, Edge* e);
    bool areAdjacent(Node* v, Node* w);

    // Methods for directed edges
    bool isDirected(Edge* e);
    void insertDirectedEdge(Node* v, Node* w, int i = 0);
    Node* origin(Edge* e);
    Node* destination(Edge* e);

    // Generic methods
    int numVertices();
    int numEdges();
    std::vector<Node*>& vertices();
    std::vector<Edge*>& edges();

    // Algorithms
    void depthFirstTraversal(Node* n);
    void breadthFirstTraversal(Node* n);
    std::vector<Edge*> primsAlgorithm();
    std::vector<Edge*> Nesten_KruskalAlgorithm();

    void dijkstrasAlgorithm(Node* n);
    void dijkstrasAlgorithm2(Node* n);
    void nullstillAlleDistance();

    std::vector<Node*> approxVertexCover();
    bool checkVertexCover(std::vector<Node *> cover);

private:
    void setAllUnvisited();
    std::vector<Node*> verticeList;
    std::vector<Edge*> allEdgeList;
};


Node* Graph::rot_Vertex()
{
    if(verticeList.size() > 0)
        return verticeList.at(0);
    else
        return nullptr;
}

void Graph::insertVertex(Node* n){
    verticeList.push_back(n);
}

void Graph::insertEdge(Node *v, Node *w, int i)
{
    Edge* e = new Edge(v, w, i);
    allEdgeList.push_back(e);
    v->edgeList.push_back(e);
    w->edgeList.push_back(e);
}

void Graph::removeEdge(Edge *e){
    /** ********************************************************************/
    vector<Edge*>::iterator aktuelle = find(allEdgeList.begin(), allEdgeList.end(), e);
    if (aktuelle!= allEdgeList.end()) {
        Edge *ed = *aktuelle;
        Node * endpoint0 = (*ed).endpoint[0];
        Node * endpoint1 = (*ed).endpoint[1];

        endpoint0->removeIncidentEdge(ed);
        endpoint1->removeIncidentEdge(ed);
        delete *aktuelle;
        allEdgeList.erase(aktuelle);
    }
}

void Graph::removeVertex(Node *n)
{
    vector<Node*>::iterator it_Node = find(verticeList.begin(),verticeList.end(), n);

    if (it_Node!=verticeList.end()) {

//        FEIL==> selv om noden er lagret på heap, vil denne setningen flyte denne til stack,også det blir ikke noe behov til å slette den med delete
//        Fordi: Når det opprettes en node på heap har den fått en adresse i minnet som ikke kan forandres. Hvis du vil flytte objektet må du lage det på nytt. Så du må altså bruke delete her!


        Node denne = **it_Node;
        //Hva er det som gjør "segfault" om "denne" blir Node-peker istedenfor Node-objekt??
        for (vector<Edge*>::iterator it_Edge = denne.edgeList.begin(); it_Edge != denne.edgeList.end()  ; ++it_Edge) {
            removeEdge(*it_Edge);  // OBS verdi til (*it_edge) er en Edge pointer
        }
        cout << "" <<endl;
        verticeList.erase(it_Node);
    }
}

std::vector<Edge*>& Graph::incidentEdges(Node *n)
{
    return n->edgeList;
}

Node** Graph::endVertices(Edge *e)  /** TODO sjekk om grafen innholder e */
{
    return e->endpoint;
}

Node* Graph::opposite(Node *n, Edge *e)
{
    if(e->endpoint[0] == n)
        return e->endpoint[1];
    else
        return e->endpoint[0];
}

bool Graph::areAdjacent(Node *v, Node *w)
{
    std::vector<Edge*>::iterator i = v->edgeList.begin();
    while(i != v->edgeList.end()){
        if((*i)->endpoint[0] == w || (*i)->endpoint[1] == w){
            return true;
        }
    }
    return false;
}

bool Graph::isDirected(Edge *e)
{
    return e->isDirected;
}

void Graph::insertDirectedEdge(Node *v, Node *w, int i)
{
    Edge* e = new Edge(v, w, i, true);
    allEdgeList.push_back(e);
    v->edgeList.push_back(e);
    w->edgeList.push_back(e);
}

Node *Graph::origin(Edge *e)
{
    if(e->isDirected)
        return e->endpoint[0];
    else
        return nullptr;
}

Node *Graph::destination(Edge *e)
{
    if(e->isDirected)
        return e->endpoint[1];
    else
        return nullptr;
}

int Graph::numVertices()
{
    return verticeList.size();
}

int Graph::numEdges()
{
    return allEdgeList.size();
}

std::vector<Node*>& Graph::vertices()
{
    return verticeList;
}

std::vector<Edge*>& Graph::edges()
{
    return allEdgeList;
}

void Graph::depthFirstTraversal(Node* n){
    setAllUnvisited();
    std::stack<Node*> verticeStack;
    verticeStack.push(n);//OBS pusher kun 1 element det rot-elementet
    while(!verticeStack.empty()){
        Node* v = verticeStack.top();
        verticeStack.pop();
        if(!v->visited){
            for(std::vector<Edge*>::iterator i = v->edgeList.begin(); i != v->edgeList.end(); i++)
                verticeStack.push(opposite(v, *i));

            std::cout << v->data << " ";
            v->visited = true;
        }
    }
    std::cout << std::endl;
}

void Graph::breadthFirstTraversal(Node* n){
    setAllUnvisited();
    std::queue<Node*> koe;
    koe.push(n);
    while (!koe.empty()) {
        Node* v = koe.front();
        koe.pop();
        if (!v->visited) {
            for (vector<Edge*>::iterator it = v->edgeList.begin(); it != v->edgeList.end(); ++it) {
                koe.push(opposite(v,*it));
            }
            cout<< v->data << " ";
            v->visited = true;
        }
    }
    cout << endl;
}

void Graph::setAllUnvisited()
{
    for(std::vector<Node*>::iterator i = verticeList.begin(); i != verticeList.end(); i++){
        (*i)->visited = false;
    }
}

/*
 *  Here we create a functor class that we can use to create a priority queue for Edges
 */
class CompareEdges
{
public:
    bool operator()(const Edge* e, const Edge* f)
    {
        /* Returns true if edge e has higher weight than edge f */
        return e->weight > f->weight;
    }
};
/**           1) s = vilkårleg startnode
        //    2) lagMinHaug(h)
        //    3) legg alle kantar som går ut frå s til h
        //    4) så lenge h ikkje tom
        //    5) e = h.fjernMin()
        //    6) viss ikkje begge endepunkta til e er med i MST
        //    7) - la w vere endepunktet til e som ikkje er med i MST
        //    8) - legg e til MST
        //    9) - legg alle kantar mellom w og nodar som ikkje er med  i MST til h
        //    10) gjenta
*/
std::vector<Edge*> Graph::primsAlgorithm(){
    setAllUnvisited();

    vector<Edge*> MST;
    priorityqueue pq;
    //Den 1. while hensikten er å sikre at vi ikke velge en startnode som ikke er knyttet til grafen, for eks node "a" etter at vi slettet node b
    vector<Node*>::iterator ind_it = verticeList.begin();

    while(pq.is_empty() && ind_it!=verticeList.end() ){
        Node* v = *ind_it;
        for (vector<Edge*>::iterator it= v->edgeList.begin() ; it!= v->edgeList.end(); ++it)
            pq.add(*it);

        ++ind_it;
    }

    while (! pq.is_empty()) {
        Edge * e = pq.remove1();

        if ( !e->endpoint[0]->visited ||  !e->endpoint[1]->visited  ) {
            MST.push_back(e);
        }
        for (int i = 0; i < 2; ++i) {
            Node* w = e->endpoint[i];
            if ( !w->visited ) {
                for (vector<Edge*>::iterator it= w->edgeList.begin() ; it!= w->edgeList.end(); ++it) {
                    pq.add(*it);
                }
                w->visited=true;
            }//if
        }//for
    }//while

    return MST;
}

std::vector<Edge*> Graph::Nesten_KruskalAlgorithm(){

    setAllUnvisited();
    auto lmp = [](Edge* e1, Edge* e2){return e1->weight < e2->weight;}; //1,2,3,4...

    vector<Edge*> MST;
    vector<Edge*> ordnet_liste = allEdgeList;
    sort(ordnet_liste.begin() , ordnet_liste.end() , lmp);
    (**ordnet_liste.begin()).endpoint[0]->visited = true;

    while (ordnet_liste.size() != 0) {
        vector<Edge*>::iterator it = ordnet_liste.begin();
        while (it !=ordnet_liste.end()) {

            //det er bug her, if setning skulle itillegg innholde " eller det ikke blir en syklus"
            if ( (**it).endpoint[0]->visited ^ (**it).endpoint[1]->visited  ) {
                MST.push_back(*it);
                (**it).endpoint[0]->visited = true;
                (**it).endpoint[1]->visited = true;
                ordnet_liste.erase(it);
            } else if((**it).endpoint[0]->visited &&  (**it).endpoint[1]->visited)
                ordnet_liste.erase(it);
            else
                ++it; //Her er hullen!
        }//for

    }//while



    return MST;
}

/*
 *  Here we create a functor class that we can use to create a priority queue for Nodes
 */
class CompareNodeDistance{
public:
    bool operator()(const Node* v, const Node* w)
    {
        /* Returns true if node v has longer path than node w */
        return v->distance > w->distance;
    }
};

void Graph::dijkstrasAlgorithm(Node *n)
{
    n->distance = 0; // skulle sjekke om grafen inholder n
    std::deque<Node*> unvisitedNodes(verticeList.begin(), verticeList.end());

    while(!unvisitedNodes.empty()){
        //Find min distance node
        //make_heap min. haug
        std::make_heap(unvisitedNodes.begin(), unvisitedNodes.end(), [](const Node* v, const Node* w) {return v->distance > w->distance;});
        Node* v = unvisitedNodes.front();
        unvisitedNodes.pop_front();
        for(std::vector<Edge*>::iterator i = v->edgeList.begin(); i != v->edgeList.end(); i++){
            Node* w = opposite(v,*i);
            int dist = v->distance + (*i)->weight;
            if( dist < w->distance ){
                w->distance = dist;
                w->previous = v;
            }
        }
    }
}


void Graph::dijkstrasAlgorithm2(Node *n)
{
    n->distance = 0; // skulle sjekke om grafen inneholder n
    std::vector<Node*> unvisitedNodes = verticeList;

    sort(unvisitedNodes.begin(), unvisitedNodes.end(), [](const Node* v, const Node* w) {return v->distance > w->distance;});
    while(unvisitedNodes.size() != 0){
        //Find min distance node
        Node* v = unvisitedNodes.back();
        unvisitedNodes.pop_back();
        for(std::vector<Edge*>::iterator i = v->edgeList.begin(); i != v->edgeList.end(); i++){
            Node* w = opposite(v,*i);
            int dist = v->distance + (*i)->weight;
            if( dist < w->distance ){
                w->distance = dist;
                w->previous = v;
            }
        }
    }
}

void Graph::nullstillAlleDistance()
{
    for (vector<Node*>::iterator it = verticeList.begin(); it != verticeList.end() ; ++it) {
        (**it).distance=INT_MAX;
    }
}

std::vector<Node*> Graph::approxVertexCover(){
    std::vector<Node*> c;
    std::vector<Edge*> e(allEdgeList.begin(), allEdgeList.end());

    while(!e.empty()){
        // Randomly choose an edge (u,v) in E’, put u and v into C;
        Edge* tmpEdge = e.back();
        e.pop_back();
        Node* u = tmpEdge->endpoint[0];
        Node* v = tmpEdge->endpoint[1];
        c.push_back(u);
        c.push_back(v);

        // Remove all the edges that are covered by u from E’
        for(std::vector<Edge*>::iterator it = u->edgeList.begin(); it != u->edgeList.end(); it++){
            std::vector<Edge*>::iterator pos = std::find(e.begin(), e.end(),*it);
            if(pos != e.end())
                e.erase(pos);
        }

        // Remove all the edges that are covered by v from E’
        for(std::vector<Edge*>::iterator it = v->edgeList.begin(); it != v->edgeList.end(); it++){
            std::vector<Edge*>::iterator pos = std::find(e.begin(), e.end(),*it);
            if(pos != e.end())
                e.erase(pos);
        }
        /** OBS EDGE-EN BLIR IKKE FJERNET FRA GRAF-LISTE*/
    }
    return c;
}

bool Graph::checkVertexCover(std::vector<Node*> cover){
    std::vector<Edge*> e(allEdgeList.begin(), allEdgeList.end());

    while(!cover.empty()){
        Node* v = cover.back();
        cover.pop_back();

        // Remove all the edges that are covered by v from E’
        for(std::vector<Edge*>::iterator it = v->edgeList.begin(); it != v->edgeList.end(); it++){
            std::vector<Edge*>::iterator pos = std::find(e.begin(), e.end(),*it);
            if(pos != e.end())
                e.erase(pos);
        }
    }
    return e.empty();
}

Graph::~Graph(){
    vector<Node*>::iterator node_it = verticeList.begin();
    while (node_it!=verticeList.end()) {
        delete *node_it;
        verticeList.erase(node_it);
    }

    vector<Edge*>::iterator edge_it= allEdgeList.begin();
    while (edge_it!=allEdgeList.end()) {
        delete *edge_it;  //OBS * ==>derefrence
        allEdgeList.erase(edge_it); //OBS erase(peker)
    }
}

#endif // GRAPH_H
