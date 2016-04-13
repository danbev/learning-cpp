#include "graph.h"
#include "../datastructures/stack.cpp"

/**
 * Finds connected components of a graph.
 *
 * This sounds similar to union-find but has some differences. In union-find
 * we can add connections whereas here we have a graph which is pre-processed
 * in the constructor performing a depth-first search and grouping vertices that
 * are connected into the same group. We can then ask if two vertices are connected
 * in constant time. Another difference is that union-find does not have to build
 * a full representation of the graph.
 * If you have a large number of queries intermixed with unions/connections union-find
 * is probably the route to go. But if you already have a graph then ConnectedComponent
 * search is suitable.
 *
 */
class ConnectedComponentSearch {
    private:
        const Graph *graph;
        bool *visited;
        int *groups;
        int count;
        void dfs(const Graph* g, int v);
    public:
        ConnectedComponentSearch(const Graph * graph);
        bool connected(int v, int w) const;
        int group(int v) const;
        int subgraphs() const;
};

ConnectedComponentSearch::ConnectedComponentSearch(const Graph *graph) : count(0) {
    this->graph = graph;
    int length = this->graph->vertices();
    visited = new bool[length] {false};
    // all vertices in the groups array with the same value are in the same group
    // and hence connected to each other
    groups = new int[length];
    // go through all vertices and if they have not been visisted, visit all the
    // vertices connected to it and add them to the same group (i)
    for (int i = 0; i < length; i++) {
        if (!visited[i]) {
            dfs(this->graph, i);
            count++;
        }
    }
}

void ConnectedComponentSearch::dfs(const Graph *g, int v) {
    visited[v] = true; // first step is to mark the vertex as visited
    groups[v] = count; // set the group that vertex v belongs to
    const IntIterator *it = g->adjacent(v);
    while(it->hasNext()) {
        int w = it->next();
        if (!visited[w]) {
            dfs(g, w);
        }
    }
}

auto ConnectedComponentSearch::connected(int v, int w) const -> bool {
    return groups[v] == groups[w];
}

auto ConnectedComponentSearch::subgraphs() const -> int {
    return count;
}

auto ConnectedComponentSearch::group(int v) const -> int {
    return groups[v];
}

