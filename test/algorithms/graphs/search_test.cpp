#include <iostream>
#include <gtest/gtest.h>
#include "undirected-graph.cpp"
#include "search.cpp"

TEST(Graph, search) {
    std::unique_ptr<UndirectedGraph> graph(new UndirectedGraph(20));
    graph->addEdge(0, 1);
    graph->addEdge(0, 2);
    graph->addEdge(0, 5);
    graph->addEdge(1, 7);
    Search search (graph.get(), 0);
    EXPECT_EQ(true, search.isConnectedToSource(1));
    EXPECT_EQ(true, search.isConnectedToSource(2));
    EXPECT_EQ(true, search.isConnectedToSource(5));
    EXPECT_EQ(false, search.isConnectedToSource(7));
}

