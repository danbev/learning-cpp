#include "graph.h"
#include "../datastructures/stack.cpp"
#include "../datastructures/queue.cpp"

namespace graphs {

    /**
     * Performs a depth first search on a digraph and stores the vertext 
     * visited pre and post processing.
     *
     * In addition to storing the post processing vertexes the reverse of 
     * this order is also made available to clients.
     *
     * These orders are useful in advanced graph-processing algoritms.
     *
     */
    class DirectedDepthFirstOrder {
        private:
            const Digraph* graph;
            Queue *pre;
            Queue *post;
            Stack *reverse;
            bool* visited;
            int *parentVertex;
            void dfs(const Digraph* g, int v);
        public:
            DirectedDepthFirstOrder(const Digraph * graph);
            Iterator<int>* preOrder() const;
            Iterator<int>* postOrder() const;
            Iterator<int>* reverseOrder() const;
    };

    DirectedDepthFirstOrder::DirectedDepthFirstOrder(const Digraph *graph) {
        this->graph = graph;
        this->pre = new Queue();
        this->post = new Queue();
        this->reverse = new Stack();
        int length = this->graph->vertices();
        visited = new bool[length] {false};
        parentVertex = new int[length];
        for (int i = 0; i < length; i++) {
            parentVertex[i] = -1;
        }
        dfs(this->graph, 0);
    }

    void DirectedDepthFirstOrder::dfs(const Digraph *g, int v) {
        pre->enqueue(v);
        visited[v] = true; // first step is to mark the vertex as visited
        Iterator<int>* it = g->adjacent(v);
        while(it->hasNext()) {
            int w = it->next();
            if (!visited[w]) {
                parentVertex[w] = v;
                dfs(g, w);
            }
        }
        post->enqueue(v);
        reverse->push(v);
    }

    Iterator<int>* DirectedDepthFirstOrder::preOrder() const {
        return pre->iterator();
    }

    Iterator<int>* DirectedDepthFirstOrder::postOrder() const {
        return post->iterator();
    }

    Iterator<int>* DirectedDepthFirstOrder::reverseOrder() const {
        return reverse->iterator();
    }

}
