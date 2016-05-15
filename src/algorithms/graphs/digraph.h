#ifndef DIGRAPH
#define DIGRAPH
#include "../datastructures/node-iterator.h"
/*
 * A directed graph where edges are one way paths between vertices.
 *
 * Terminology:
 * Edge: a one way path between two vertices.
 * Directed path: in a graph is a sequence of vertices where there is an edge pointing from each
 *                vertex to its successor (comes after).
 * Simple path: is a path with no repeated vertices.
 * Directed cycle: is a directed path with at least one edge whose first and last vertices are the same.
 * Length: the number of edges in the path/cycle.
 *
 */
class Digraph {
    public:
        virtual int vertices() const = 0;
        virtual int edges() const = 0;
        virtual void addEdge(int v, int w) = 0;
        virtual NodeIterator<int>* adjacent(int v) const = 0;
        virtual Digraph* reverse() const = 0;
        virtual ~Digraph() {};
};
#endif
