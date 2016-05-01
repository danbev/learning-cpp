#include <iostream>
#include <gtest/gtest.h>
#include "directed-graph.cpp"
#include "topological.cpp"

TEST(Toplogical, create) {
  DirectedGraph graph {10};
  graph.addEdge(0, 1);
  graph.addEdge(1, 2);
  graph.addEdge(2, 3);
  graph.addEdge(0, 4);
  const graphs::Topological topo {&graph};
  IntIterator* it = topo.order();
  EXPECT_EQ(true, it->hasNext());
  EXPECT_EQ(0, it->next());
  EXPECT_EQ(1, it->next());
  EXPECT_EQ(2, it->next());
  EXPECT_EQ(3, it->next());
  EXPECT_EQ(4, it->next());
  EXPECT_EQ(false, it->hasNext());
}

