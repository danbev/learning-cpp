#include <iostream>
#include <gtest/gtest.h>
#include "directed-graph.cpp"
#include "directed-cycle.cpp"

TEST(DirectedCycle, acyclic) {
    DirectedGraph graph {10};
    graph.addEdge(0, 2);
    graph.addEdge(2, 4);
    graph.addEdge(2, 3);
    graph.addEdge(3, 5);
    const DirectedCycle cycle (&graph);
    EXPECT_EQ(false, cycle.hasCycle());
}

/*
 * (0)--------->(1)
 *  /\           |
 *  |            |
 * (3)<---------(2)
 */
TEST(DirectedCycle, cyclic) {
    DirectedGraph graph {6};
    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(2, 3);
    graph.addEdge(3, 0);
    const DirectedCycle cycle (&graph);
    EXPECT_EQ(true, cycle.hasCycle());
    IntIterator* it = cycle.cycle();
    EXPECT_EQ(3, it->next());
    EXPECT_EQ(0, it->next());
    EXPECT_EQ(1, it->next());
    EXPECT_EQ(2, it->next());
}

