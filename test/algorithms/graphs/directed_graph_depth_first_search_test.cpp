#include <iostream>
#include <gtest/gtest.h>
#include "directed-graph.cpp"
#include "directed-graph-depth-first-search.cpp"

TEST(DigraphDepthFirstSearch, search) {
    DirectedGraph graph {10};
    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(2, 3);
    graph.addEdge(4, 5);
    DigraphDepthFirstSearch search (&graph, 0);
    EXPECT_EQ(true, search.hasPathFromSource(1));
    EXPECT_EQ(true, search.hasPathFromSource(2));
    EXPECT_EQ(true, search.hasPathFromSource(3));
    EXPECT_EQ(false, search.hasPathFromSource(4));
    EXPECT_EQ(false, search.hasPathFromSource(5));
}

