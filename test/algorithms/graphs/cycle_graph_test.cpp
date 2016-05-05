#include <iostream>
#include <gtest/gtest.h>
#include "undirected-graph.cpp"
#include "cycle-graph.cpp"

TEST(CycleGraph, cyclic) {
    UndirectedGraph graph {5};
    //     (0)-------(1)
    //      |         |
    //     (2)-------(3)
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(2, 3);
    graph.addEdge(1, 3);
    const CycleGraph cycle (&graph);
    EXPECT_EQ(true, cycle.cycle());
}

TEST(CycleGraph, acyclic) {
    UndirectedGraph graph {4};
    //     (0)       (1)
    //      |         |
    //     (2)-------(3)
    graph.addEdge(0, 2);
    graph.addEdge(2, 3);
    graph.addEdge(1, 3);
    const CycleGraph cycle (&graph);
    EXPECT_EQ(false, cycle.cycle());
}
