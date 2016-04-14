#include <iostream>
#include <gtest/gtest.h>
#include "undirected-graph.cpp"
#include "connected-component-search.cpp"

TEST(ConnectedComponentSearch, pathTo) {
    int vertices = 8; // zero based number of vertices in the graph
    UndirectedGraph graph {vertices};
    graph.addEdge(0, 5);
    graph.addEdge(2, 4);
    graph.addEdge(2, 3);
    graph.addEdge(1, 2);
    graph.addEdge(0, 1);
    graph.addEdge(3, 4);
    graph.addEdge(3, 5);
    graph.addEdge(0, 2);
    graph.addEdge(7, 6);
    
    const ConnectedComponentSearch search (&graph);
    EXPECT_EQ(true, search.connected(0, 5));
    EXPECT_EQ(0, search.component(0));
    EXPECT_EQ(0, search.component(5));
    EXPECT_EQ(true, search.connected(0, 3));
    EXPECT_EQ(2, search.components());
}

