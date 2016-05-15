#include "graph.h"
#include <iostream>
#include "../datastructures/stack.cpp"

/*
 * Used depth first to search the Graph and detect if the graph is biparte.
 *
 * Bipartite: a graph whose vertices we can divide into two sets so that all
 *            edges connect a vertex in one set with a vertex in the other set.
 *
 * [V={a,b,c,d,f}]
 *               (a)---------------(b)
 *
 * [V1={a,b,c}]  (c)---------------(d)  [V2={b,d}]
 *                                /
 *               (f)-------------/
 * Any vertices that have an edge betwwen them have to go into separate subsets.
 * There is an edge between a and b so they have to be in different subsets.
 * There is an edge between c and d so they have to be in different subsets.
 * There is an edge between f and d so they have to be in different subsets.
 * V1 ∩ V2 = 0    The two set should not have any vertices in common.
 * V1 u V2 = V    The union of both sets should include all vertices.
 *
 * ∩ = intersection, all the members of both sets
 * u = union, all the members contained in either set or both
 */
class BiparteGraph {
    private:
        const Graph* graph;
        bool* visited;
        bool* color;
        void dfs(const Graph* g, int v);
        bool biparte;
    public:
        BiparteGraph(const Graph * graph);
        bool isBiparte() const;
};

BiparteGraph::BiparteGraph(const Graph *graph) : biparte(true) {
    this->graph = graph;
    int length = this->graph->vertices();
    visited = new bool[length] {false};
    color = new bool[length] {false};
    for (int v = 0; v < length; v++) {
        dfs(this->graph, v);
    }
}

void BiparteGraph::dfs(const Graph *g, int v) {
    visited[v] = true; // first step is to mark the vertex as visited
    Iterator<int>* it = g->adjacent(v);
    while(it->hasNext()) {
        int w = it->next();
        if (!visited[w]) {
            // set the color of the current vertex w to be the inverse of it's parent
            color[w] = !color[v];
            dfs(g, w);
        } else if (color[w] == color[v]) {
            // if we find a vertex that has the same color as its parent it cannot 
            // be bipartite
            biparte = false;
        }
    }
}

bool BiparteGraph::isBiparte() const {
    return biparte;
}
