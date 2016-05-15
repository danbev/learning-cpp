#include <iostream>
#include <gtest/gtest.h>
#include "directed-graph.cpp"
#include "directed-breadth-first-path-search.cpp"

/*
 *   (0)________>(2)
 *    |         /   \
 *    |        /     \
 *   (5)----(3)-----(4)
 */
TEST(DirectedBreadthFirstPathSearch, pathTo) {
    DirectedGraph graph {20};
    graph.addEdge(0, 2);
    graph.addEdge(2, 3);
    graph.addEdge(2, 4);
    graph.addEdge(3, 5);
    graph.addEdge(0, 5);
    const DirectedBreadthFirstPathSearch search (&graph, 0);
    NodeIterator<int>* it = search.pathTo(5);
    EXPECT_EQ(0, it->next());
    EXPECT_EQ(5, it->next());
    EXPECT_EQ(false, it->hasNext());
}

