#include <gtest/gtest.h>
#include <iostream>

using namespace std;

TEST(decltype, basic) {
  int x = 10;
  // make y the same type as x
  decltype (x) y = 20;
  EXPECT_EQ(x, 10);
  EXPECT_EQ(y, 20);
}

