#include "../datastructures/int-iterator.h"
#ifndef DIGRAPH
#define DIGRAPH
class Digraph {
    public:
        virtual int vertices() const = 0;
        virtual int edges() const = 0;
        virtual void addEdge(int v, int w) = 0;
        virtual const IntIterator* adjacent(int v) const = 0;
        virtual const Digraph* reverse() const = 0;
};
#endif
