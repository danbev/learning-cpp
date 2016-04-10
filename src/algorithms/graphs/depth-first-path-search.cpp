#include "graph.h"
#include <iostream>
#include "../datastructures/stack.cpp"

class DepthFirstPathSearch {
    private:
        const Graph* graph;
        int s;
        bool* visited;
        int *parentVertex;
        int count;
        void dfs(const Graph* g, int v);
    public:
        DepthFirstPathSearch(const Graph * graph, int s);
        bool isConnectedToSource(int v) const;
        int visitedVertices() const;
        const IntIterator* pathTo(int v) const;
};

DepthFirstPathSearch::DepthFirstPathSearch(const Graph *graph, int s) {
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

/*
 * The time taken is proportional to the sum of the the vertices degrees.
 * Incident: if there is an edge connecting two vertices, the edge is said to be indicent
 *           to the vertices.
 * Degree: the degree of a vertex is the number of edges incident to it.
 */
void DepthFirstPathSearch::dfs(const Graph *g, int v) {
    visited[v] = true; // first step is to mark the vertex as visited
    count++;
    const IntIterator *it = g->adjacent(v);
    std::cout << __func__ << ": Processing v = " << v << std::endl;
    while(it->hasNext()) {
        int w = it->next();
        if (!visited[w]) {
            parentVertex[w] = v;
            std::cout << "\t w = " << w << " setting parent to " << v << std::endl;
            dfs(g, w);
        }
    }
}

auto DepthFirstPathSearch::pathTo(int v) const -> const IntIterator * {
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

auto DepthFirstPathSearch::isConnectedToSource(int v) const -> bool {
    std::cout << __func__ << ": is " << v << " connected to " << s << std::endl;
    return visited[v];
}

auto DepthFirstPathSearch::visitedVertices() const -> int {
    return count;
}
