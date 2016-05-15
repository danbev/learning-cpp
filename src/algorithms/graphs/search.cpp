#include "graph.h"
#include <iostream>

class Search {
    private:
        const Graph* graph;
        int s;
        bool* connected;
        void populateConnected();
    public:
        Search(const Graph * graph, int s);
        // is v connected to s
        bool isConnectedToSource(int v) const;
        // how many vertices are connected to s
        int connectedVertices() const;
};

Search::Search(const Graph *graph, int s) {
    this->graph = graph;
    this->s = s;
    populateConnected();
}
void Search::populateConnected() {
    int vertices = this->graph->vertices();
    connected = new bool[vertices] {false};
    Iterator<int> *it = this->graph->adjacent(s);
    while(it->hasNext()) {
        int v = it->next();
        connected[v] = true;
    }
}

bool Search::isConnectedToSource(int v) const {
    return connected[v];
}

int Search::connectedVertices() const {
    return sizeof(connected) / sizeof(bool);
}
