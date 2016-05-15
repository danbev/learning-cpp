#include <iostream>
#include <gtest/gtest.h>
#include "directed-graph.cpp"
#include "directed-depth-first-order.cpp"

TEST(DirectedDepthFirstOrder, order) {
    DirectedGraph graph {10};
    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(2, 3);
    const graphs::DirectedDepthFirstOrder t (&graph);

    Iterator<int>* pre = t.preOrder();
    EXPECT_EQ(0, pre->next());
    EXPECT_EQ(1, pre->next());
    EXPECT_EQ(2, pre->next());
    EXPECT_EQ(3, pre->next());
    EXPECT_EQ(false, pre->hasNext());

    Iterator<int>* post = t.postOrder();
    EXPECT_EQ(3, post->next());
    EXPECT_EQ(2, post->next());
    EXPECT_EQ(1, post->next());
    EXPECT_EQ(0, post->next());
    EXPECT_EQ(false, post->hasNext());

    Iterator<int>* rev = t.reverseOrder();
    EXPECT_EQ(0, rev->next());
    EXPECT_EQ(1, rev->next());
    EXPECT_EQ(2, rev->next());
    EXPECT_EQ(3, rev->next());
    EXPECT_EQ(false, rev->hasNext());
}

