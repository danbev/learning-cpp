#include "digraph.h"

/**
 * A depth first search using a directed graph.
 */
class DigraphDepthFirstSearch {
    private:
        const Digraph* graph;
        int source;
        bool* visited;
        int count;
        void dfs(const Digraph* g, int v);
    public:
        DigraphDepthFirstSearch(const Digraph * graph, int source);
        bool hasPathFromSource(int v) const;
        int visitedVertices() const;
};

DigraphDepthFirstSearch::DigraphDepthFirstSearch(const Digraph *graph, int source) {
    this->graph = graph;
    this->source = source;
    this->count = 1;
    visited = new bool[this->graph->vertices()] {false};
    dfs(this->graph, source);
}

void DigraphDepthFirstSearch::dfs(const Digraph *g, int v) {
    visited[v] = true; // first step is to mark the vertex as visited
    count++;
    const IntIterator *it = g->adjacent(v);
    while(it->hasNext()) {
        int w = it->next();
        if (!visited[w]) {
            dfs(g, w);
        }
    }
}

/**
 * Is there a directed path from the source vertex to the passed-in vertex v.
 */
auto DigraphDepthFirstSearch::hasPathFromSource(int v) const -> bool {
    return visited[v];
}

auto DigraphDepthFirstSearch::visitedVertices() const -> int {
    return count;
}
