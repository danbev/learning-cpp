#ifndef DIRECTED_GRAPH
#define DIRECTED_GRAPH
#include <stdio.h>
#include "digraph.h"
#include "../datastructures/bag.cpp"

/*
 * A directed graph where edges are one way paths between vertices.
 */
class DirectedGraph : public Digraph {
    private:
        int v;
        int e;
        Bag<int>** bags;

    public:
        DirectedGraph(int vertices);
        ~DirectedGraph();
        int vertices() const;
        int edges() const;
        void addEdge(int v, int w);
        Iterator<int>* adjacent(int v) const;
        Digraph* reverse() const;
};

DirectedGraph::DirectedGraph(int vertices) {
    this->v = vertices;
    this->bags = new Bag<int>*[vertices];
    for (int i = 0; i < vertices; i++) {
        bags[i] = new Bag<int>();
    }
    this->e = 0;
}

DirectedGraph::~DirectedGraph() {
    delete [] bags;
}

int DirectedGraph::vertices() const {
    return v;
}

int DirectedGraph::edges() const {
    return e;
}

void DirectedGraph::addEdge(int v, int w) {
    // only v->w (not both like in an undirected graph
    bags[v]->add(w);
    e++;
}

Iterator<int>* DirectedGraph::adjacent(int v) const {
    return bags[v]->iterator();
}

/**
 * Returns a copy of this DirectedGraph but with all edges reversed.
 */
Digraph* DirectedGraph::reverse() const {
    DirectedGraph* rev = new DirectedGraph(v);
    for (int i = 0; i < v; i++) {
        Iterator<int>* it = adjacent(i);
        while (it->hasNext()) {
            rev->addEdge(it->next(), i);
        }
    }
    return rev;
}
#endif
