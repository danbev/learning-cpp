#include <iostream>
#include <gtest/gtest.h>
#include "undirected-graph.cpp"
#include "depth-first-path-search.cpp"

/*
 *   (0)_________ (2)
 *    |  \   /  /   \
 *    |   (1)  /     \
 *   (5)----(3)-----(4)
 */
TEST(DeptFirstPathSearch, pathTo) {
    UndirectedGraph graph {20};
    graph.addEdge(0, 5);
    graph.addEdge(2, 4);
    graph.addEdge(2, 3);
    graph.addEdge(1, 2);
    graph.addEdge(0, 1);
    graph.addEdge(3, 4);
    graph.addEdge(3, 5);
    graph.addEdge(0, 2);
    // the order of the underlying dag is an array of bags. On bag for each vertex:
    // 0 = {5, 1, 2}
    // 1 = {2, 0}
    // 2 = {4, 3, 1, 0}
    // 3 = {2, 4, 5}
    // 4 = {2, 3}
    // 5 = {0, 3}
    
    const DepthFirstPathSearch search (&graph, 0);
    // DepthFirstPathSearch only keeps track of the parent vertexes for the graph by processing 
    // the graph depth first. That is taking the first adjacent vertex and processing it and its 
    // subpaths recursively.

    NodeIterator<int>* it = search.pathTo(5);
    EXPECT_EQ(0, it->next());
    EXPECT_EQ(2, it->next());
    EXPECT_EQ(3, it->next());
    EXPECT_EQ(5, it->next());
    EXPECT_EQ(false, it->hasNext());
}

