#include "graph.h"
#include "../datastructures/stack.cpp"

class DirectedDepthFirstPathSearch {
    private:
        const Digraph* graph;
        int s;
        bool* visited;
        int *parentVertex;
        int count;
        void dfs(const Digraph* g, int v);
    public:
        DirectedDepthFirstPathSearch(const Digraph * graph, int s);
        bool isConnectedToSource(int v) const;
        int visitedVertices() const;
        IntIterator* pathTo(int v) const;
};

DirectedDepthFirstPathSearch::DirectedDepthFirstPathSearch(const Digraph *graph, int s) {
    this->graph = graph;
    this->s = s;
    this->count = 1;
    int length = this->graph->vertices();
    visited = new bool[length] {false};
    parentVertex = new int[length];
    for (int i = 0; i < length; i++) {
        parentVertex[i] = -1;
    }
    dfs(this->graph, s);
}

void DirectedDepthFirstPathSearch::dfs(const Digraph *g, int v) {
    visited[v] = true; // first step is to mark the vertex as visited
    count++;
    IntIterator *it = g->adjacent(v);
    while(it->hasNext()) {
        int w = it->next();
        if (!visited[w]) {
            parentVertex[w] = v;
            dfs(g, w);
        }
    }
}

IntIterator* DirectedDepthFirstPathSearch::pathTo(int v) const {
    if (!isConnectedToSource(v)) {
        // TODO: return an empty IntIterator
        return nullptr;
    }
    Stack stack;
    for (int i = v; i != s; i = parentVertex[i]) {
        stack.push(i);
    }
    stack.push(s);
    return stack.iterator();
}

bool DirectedDepthFirstPathSearch::isConnectedToSource(int v) const {
    return visited[v];
}

int DirectedDepthFirstPathSearch::visitedVertices() const {
    return count;
}
