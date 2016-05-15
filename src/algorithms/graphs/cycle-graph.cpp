#include "graph.h"
#include <iostream>
#include "../datastructures/stack.cpp"

/*
 * Uses depth first to search the Graph and detect if a cycle exists.
 *
 */
class CycleGraph {
    private:
        const Graph* graph;
        bool* visited;
        void dfs(const Graph* g, int v, int u);
        bool cycle_;
    public:
        CycleGraph(const Graph * graph);
        bool cycle() const;
};

CycleGraph::CycleGraph(const Graph *graph) {
    this->graph = graph;
    int length = this->graph->vertices();
    visited = new bool[length] {false};
    for (int v = 0; v < length; v++) {
        if (!visited[v]) {
            dfs(this->graph, v, v);
        }
    }
}

void CycleGraph::dfs(const Graph *g, int v, int u) {
    visited[v] = true; 
    Iterator<int>* it = g->adjacent(v);
    while(it->hasNext()) {
        int w = it->next();
        if (!visited[w]) {
            dfs(g, w, v);
        } 
        // if vertex w has already been visited/marked but is the same as the "parent" 
        // or the vertex that we came from, then this does not indicate a cycle as that 
        // is simply a connection in the graph.
        // But lets say that another adjacent vertex w, which remember has already been
        // visited/marked, but is not equal to the parent this indicates that we have 
        // circled around. If w had not been visisted we could have recursed into dfs
        // again.
        else if (w != u) { 
            cycle_ = true;
        }
    }
}

bool CycleGraph::cycle() const {
    return cycle_;
}
