#ifndef EDGE_WEIGHTED_GRAPH_H
#define EDGE_WEIGHTED_GRAPH_H
#include "edge.h"

/**
 * A graph with weighted edges.
 */
class EdgeWeightedGraph {
    public:
        virtual int vertices() const = 0;
        virtual int edges() const = 0;
        virtual void addEdge(Edge edge) = 0;
        virtual Iterator<Edge>* adjacent(int v) const = 0;
        virtual Iterator<Edge>* edges() const = 0;
}
#endif
