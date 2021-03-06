#include "edge-weighted-graph.h"
#include "../datastructures/bag.cpp"

EdgeWeightedGraph::EdgeWeightedGraph(int vertices) {
    this->v = vertices;
    this->bags = new Bag<Edge>*[vertices];
    for (int i = 0; i < vertices; i++) {
        bags[i] = new Bag<Edge>();
    }
    this->e = 0;
}

EdgeWeightedGraph::~EdgeWeightedGraph() {
    delete [] bags;
}

int EdgeWeightedGraph::vertices() const {
    return v;
}

void EdgeWeightedGraph::addEdge(Edge edge) {
    int v = edge.either();
    int w = edge.other(v);
    bags[v]->add(edge);
    bags[w]->add(edge);
    e++;
}

Iterator<Edge>* EdgeWeightedGraph::adjacent(int v) const {
    return bags[v]->iterator();
}

Iterator<Edge>* EdgeWeightedGraph::edges() const {
    return bags[v]->iterator();
}
