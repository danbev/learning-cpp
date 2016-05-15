#include "graph.h"
#include "../datastructures/stack.cpp"
#include "../datastructures/queue.cpp"

class DirectedBreadthFirstPathSearch {
    private:
        const Digraph* graph;
        int s;
        bool* visited;
        int *parentVertex;
        int count;
        void bfs(const Digraph* g, int v);
    public:
        DirectedBreadthFirstPathSearch(const Digraph * graph, int s);
        bool isConnectedToSource(int v) const;
        int visitedVertices() const;
        Iterator<int>* pathTo(int v) const;
};

DirectedBreadthFirstPathSearch::DirectedBreadthFirstPathSearch(const Digraph *graph, int s) {
    this->graph = graph;
    this->s = s;
    this->count = 0;
    int length = this->graph->vertices();
    visited = new bool[length] {false};
    parentVertex = new int[length];
    for (int i = 0; i < length; i++) {
        parentVertex[i] = -1;
    }
    bfs(this->graph, s);
}

void DirectedBreadthFirstPathSearch::bfs(const Digraph *g, int s) {
    Queue queue;
    visited[s] = true; // mark the source
    queue.enqueue(s);
    while (!queue.empty()) {
        count++;
        int v = queue.dequeue();
        Iterator<int>* it = g->adjacent(v);
        while (it->hasNext()) {
            int w = it->next();
            if (!visited[w]) {
                parentVertex[w] = v;
                visited[w] = true;
                queue.enqueue(w);
            }
        }
    }
}

Iterator<int>* DirectedBreadthFirstPathSearch::pathTo(int v) const {
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

bool DirectedBreadthFirstPathSearch::isConnectedToSource(int v) const {
    return visited[v];
}

int DirectedBreadthFirstPathSearch::visitedVertices() const {
    return count;
}
