#include "graph.h"
#include "../datastructures/stack.cpp"

/**
 * Determines is a digraph has a cycle and if so return the vertices
 * of that cycle.
 *
 * Some use case do not allow for a cycle to be present. For example if
 * you have a number of jobs a, b, and c. And a must be done before b,
 * and b before c, and c before a we have:
 *     (a)----->(b)
 *     / \       |
 *        \      |
 *          \    \/
 *            - (c)
 * This can be used to answer whether a graph is a Directed Acyclic Graph (DAG).
 *
 * For a use case of a DAG you can think of how git works. It has vertexes that are
 * commits and edges from a child to one or more parents.
 */
class DirectedCycle {
    private:
        const Digraph* graph;
        bool* visited;
        Stack* stack;
        bool* onstack;
        int *parentVertex;
        void dfs(const Digraph* g, int v);
    public:
        DirectedCycle(const Digraph * graph);
        IntIterator* cycle() const;
        bool hasCycle() const;
};

DirectedCycle::DirectedCycle(const Digraph *graph) {
    this->graph = graph;
    this->stack = nullptr;
    int length = this->graph->vertices();
    visited = new bool[length] {false};
    onstack = new bool[length] {false};
    parentVertex = new int[length];
    for (int i = 0; i < length; i++) {
        parentVertex[i] = -1;
    }
    dfs(this->graph, 0);
}

void DirectedCycle::dfs(const Digraph *g, int v) {
    // keep track of the vertex currently being processed.
    onstack[v] = true;
    visited[v] = true;
    IntIterator *it = g->adjacent(v);
    while(it->hasNext()) {
        // check if the last recursion found a cycle
        if (hasCycle()) {
            return;
        }
        int w = it->next();
        if (!visited[w]) {
            parentVertex[w] = v;
            dfs(g, w);
        } else if (onstack[w]) {
            // if vertex w is already on the stack it means that we have already visited
            // this vertex when recursively processing vertex v so we have a cycle.
            stack = new Stack();
            for (int i = v; i != w; i = parentVertex[i]) {
                stack->push(i);
            }
            stack->push(w);
            stack->push(v);
        }
    }
    onstack[v] = false;
}

IntIterator* DirectedCycle::cycle() const {
    return stack->iterator();
}

bool DirectedCycle::hasCycle() const {
    return stack != nullptr;
}
