#include <iostream>
#include <gtest/gtest.h>
#include "undirected-graph.cpp"
#include "biparte-graph.cpp"

TEST(BiparteGraph, biparte) {
    UndirectedGraph graph {7};
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(0, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 5);
    graph.addEdge(3, 6);
    //       (0)------(1)
    //      /   \      |
    //    (2)   (3)    |
    //   /        \    |
    //  (5)       (7) (4)
    //
    // What we are looking is if we can divide the above graph into two sets
    // so that all edges connect a vertex in one set with the ones in the other.
    //       (0)-----[(1)]
    //      /   \      |
    //   [(2)] [(3)]   |
    //   /        \    |
    //  (5)       (6) (4)
    // {1, 2, 3} match this and we say that these have a different color in the code.
    const BiparteGraph biparte (&graph);
    EXPECT_EQ(true, biparte.isBiparte());
}

TEST(BiparteGraph, nonBiparte) {
    UndirectedGraph graph {8};
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(0, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 5);
    graph.addEdge(1, 3);
    graph.addEdge(3, 6);
    //       (0)------(1)
    //      /   \    / |
    //    (2)    (3)   |
    //   /        \    |
    //  (5)       (7) (4)
    //
    // What we are looking is if we can divide the above graph into two sets
    // so that all edges connect a vertex in one set with the ones in the other.
    //       (0)-----(1)
    //      /   \   /  |
    //   (2)    (3)    |
    //   /        \    |
    //  (5)       (7) (4)
    // When vertex 1 is processed its adjacent vertices will be {3, 4}. Processing 3 and 3 has not been visited
    // we will set its color to the inverse of the color of 1. But 3 will be visited again and that we will
    // check its color against the color of the 0 which will be the same. 
    const BiparteGraph biparte (&graph);
    EXPECT_EQ(false, biparte.isBiparte());
}
