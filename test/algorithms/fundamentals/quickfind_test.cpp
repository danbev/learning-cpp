#include <gtest/gtest.h>
#include "quickfind.cpp"

TEST(quickunion, initialize) {
  QuickFind qf (10);
  EXPECT_EQ(10, qf.components());
}

TEST(quickunion, connected) {
  QuickFind qf (10);
  EXPECT_FALSE(qf.connected(0, 1));
  qf.connect(0, 1);
  EXPECT_TRUE(qf.connected(0, 1));
}

