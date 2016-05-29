#include <gtest/gtest.h>
#include "edge-weighted-graph.cpp"

TEST(EdgeWeightedGraph, adjaent) {
  EdgeWeightedGraph graph {20};
  graph.addEdge(Edge{0, 1, 0});
  graph.addEdge(Edge{0, 2, 1});
  graph.addEdge(Edge{0, 5, 2});
  Iterator<Edge>* iter = graph.adjacent(0);
  EXPECT_EQ(true, iter->hasNext());
}

