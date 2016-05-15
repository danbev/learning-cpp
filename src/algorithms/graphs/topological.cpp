#ifndef TOPOLOGICAL
#define TOPOLOGICAL
#include "directed-cycle.cpp"
#include "directed-depth-first-order.cpp"

namespace graphs {

    class Topological {
        private:
            Iterator<int>* ord;

        public:
            Topological(const DirectedGraph *digraph);
            Iterator<int>* order() const;
    };

    Topological::Topological(const DirectedGraph* digraph) {
        const DirectedCycle cycle {digraph};
        if (!cycle.hasCycle()) {
            const DirectedDepthFirstOrder dfs {digraph};
            ord = dfs.reverseOrder();
        }
    }

    Iterator<int>* Topological::order() const {
        return ord;
    }

}
#endif
