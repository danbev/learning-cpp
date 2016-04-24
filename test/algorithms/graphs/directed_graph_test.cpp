#include <iostream>
#include <gtest/gtest.h>
#include "directed-graph.cpp"

TEST(DirectedGraph, size) {
  DirectedGraph graph {20};
  EXPECT_EQ(20, graph.vertices());
}

TEST(DirectedGraph, add) {
  DirectedGraph graph {20};
  graph.addEdge(0, 1);
  EXPECT_EQ(1, graph.edges());
}

TEST(DirectedGraph, adjaent) {
  DirectedGraph graph {20};
  graph.addEdge(0, 1);
  graph.addEdge(0, 2);
  graph.addEdge(0, 5);
  const IntIterator* iter = graph.adjacent(0);
  EXPECT_EQ(5, iter->next());
  EXPECT_EQ(2, iter->next());
  EXPECT_EQ(1, iter->next());
}

TEST(DirectedGraph, adjaentFive) {
  DirectedGraph graph {20};
  graph.addEdge(0, 1);
  graph.addEdge(0, 2);
  graph.addEdge(0, 5);
  EXPECT_EQ(true, graph.adjacent(0)->hasNext());
  EXPECT_EQ(false, graph.adjacent(5)->hasNext());
  EXPECT_EQ(false, graph.adjacent(2)->hasNext());
}

TEST(DirectedGraph, reverse) {
  DirectedGraph graph {10};
  graph.addEdge(0, 1);
  graph.addEdge(0, 2);
  graph.addEdge(0, 5);
  Digraph* rev = graph.reverse();
  EXPECT_EQ(false, rev->adjacent(0)->hasNext());
  EXPECT_EQ(true, rev->adjacent(1)->hasNext());
  EXPECT_EQ(0, rev->adjacent(1)->next());
  EXPECT_EQ(true, rev->adjacent(2)->hasNext());
  EXPECT_EQ(0, rev->adjacent(2)->next());
  EXPECT_EQ(true, rev->adjacent(5)->hasNext());
  EXPECT_EQ(0, rev->adjacent(5)->next());
}

