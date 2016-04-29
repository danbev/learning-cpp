#include "graph.h"
#include <iostream>
#include "../datastructures/stack.cpp"
#include "../datastructures/queue.cpp"

class BreadthFirstPathSearch {
    private:
        const Graph* graph;
        int s;
        bool* visited;
        int *parentVertex;
        int count;
        void bfs(const Graph* g, int v);
    public:
        BreadthFirstPathSearch(const Graph * graph, int s);
        bool isConnectedToSource(int v) const;
        int visitedVertices() const;
        const IntIterator* pathTo(int v) const;
};

BreadthFirstPathSearch::BreadthFirstPathSearch(const Graph *graph, int s) {
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

void BreadthFirstPathSearch::bfs(const Graph *g, int s) {
    Queue queue;
    visited[s] = true; // mark the source
    queue.enqueue(s);
    while (!queue.empty()) {
        count++;
        int v = queue.dequeue();
        const IntIterator *it = g->adjacent(v);
        while (it->hasNext()) {
            int w = it->next();
            if (!visited[w]) {
                parentVertex[w] = v;
                visited[w] = true;
                // we don't recurse like in depth first but instead add the vertex
                // to the queue to be processed.
                //   (0)-------(1)------(2)
                //    |
                //   (3)
                //   so processing 0 would visit 1 mark it and put it on the queue.
                //   next, 3 would be processed and put on the queue. That would be
                //   the end of processing 0 as all its adjacent vertices have been
                //   processed. At this point the queue contains 1 and 3. So we can
                //   see that the closest vertices are processed first and then it 
                //   spanns out.
                queue.enqueue(w);
            }
        }
    }
}

auto BreadthFirstPathSearch::pathTo(int v) const -> const IntIterator * {
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

auto BreadthFirstPathSearch::isConnectedToSource(int v) const -> bool {
    std::cout << __func__ << ": is " << v << " connected to " << s << std::endl;
    return visited[v];
}

auto BreadthFirstPathSearch::visitedVertices() const -> int {
    return count;
}
