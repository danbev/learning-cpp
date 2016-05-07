#include <gtest/gtest.h>
#include "edge.cpp"

TEST(Edge, other) {
    Edge edge {0, 2, 10};
    EXPECT_EQ(0, edge.other(2));
    EXPECT_EQ(2, edge.other(0));
}

TEST(Edge, either) {
    Edge edge {0, 2, 10};
    EXPECT_EQ(0, edge.either());
}

TEST(Edge, compare) {
    Edge e1 {0, 2, 10};
    Edge e2 {0, 2, 9};
    Edge e3 {0, 2, 9};
    EXPECT_EQ(1, e1.compare(e2));
    EXPECT_EQ(-1, e2.compare(e1));
    EXPECT_EQ(0, e2.compare(e3));
}
