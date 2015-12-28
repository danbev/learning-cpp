#include <gtest/gtest.h>
#include "quickunion.cpp"

TEST(quickunion, one) {
  QuickUnion qu (10);
  EXPECT_EQ(10, qu.components());
  EXPECT_FALSE(qu.connected(0, 1));
  qu.connect(0, 1);
  EXPECT_TRUE(qu.connected(0, 1));
}

