#ifndef EDGE_WEIGHTED_GRAPH_H
#define EDGE_WEIGHTED_GRAPH_H
#include "edge.h"
#include "../datastructures/bag.cpp"

/**
 * An undirected graph with weighted edges.
 */
class EdgeWeightedGraph {
    private:
        int v;
        int e;
        Bag<Edge>** bags;
    public:
        EdgeWeightedGraph(int vertices);
        ~EdgeWeightedGraph();
        int vertices() const;
        void addEdge(Edge edge);
        Iterator<Edge>* adjacent(int v) const;
        Iterator<Edge>* edges() const;
};
#endif
