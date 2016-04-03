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

TEST(Graph, adjaent) {
  UndirectedGraph graph {20};
  graph.addEdge(0, 1);
  graph.addEdge(0, 2);
  graph.addEdge(0, 5);
  const IntIterator* iter = graph.adjacent(0);
  EXPECT_EQ(5, iter->next());
  EXPECT_EQ(2, iter->next());
  EXPECT_EQ(1, iter->next());
}

