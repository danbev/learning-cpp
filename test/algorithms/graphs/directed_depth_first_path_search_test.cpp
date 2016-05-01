#include <iostream>
#include <gtest/gtest.h>
#include "directed-graph.cpp"
#include "directed-depth-first-path-search.cpp"

/*
 * (Edges are directed)
 *   (0)________>(2)
 *              /   \
 *            \/    \/
 *   (5)<---(3)<----(4)
 */
TEST(DirectedDepthFirstPathSearch, pathTo) {
    DirectedGraph graph {10};
    graph.addEdge(0, 2);
    graph.addEdge(2, 4);
    graph.addEdge(2, 3);
    graph.addEdge(3, 5);

    const DirectedDepthFirstPathSearch search (&graph, 0);
    IntIterator* it = search.pathTo(5);
    EXPECT_EQ(0, it->next());
    EXPECT_EQ(2, it->next());
    EXPECT_EQ(3, it->next());
    EXPECT_EQ(5, it->next());
    EXPECT_EQ(false, it->hasNext());
}

