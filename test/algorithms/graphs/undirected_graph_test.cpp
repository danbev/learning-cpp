#include <iostream>
#include <gtest/gtest.h>
#include "undirected-graph.cpp"

TEST(Graph, size) {
  UndirectedGraph graph {20};
  EXPECT_EQ(20, graph.vertices());
}

TEST(Graph, add) {
  UndirectedGraph graph {20};
  graph.addEdge(0, 1);
  EXPECT_EQ(1, graph.edges());
}

