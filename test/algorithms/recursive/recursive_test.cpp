#include <gtest/gtest.h>

#include "recursive.cpp"

TEST(triangle, one) {
  EXPECT_EQ(1, triangle(1));
  EXPECT_EQ(3, triangle(2));
  EXPECT_EQ(6, triangle(3));
  EXPECT_EQ(10, triangle(4));
  EXPECT_EQ(15, triangle(5));
}

TEST(factorial, one) {
  EXPECT_EQ(1, factorial(0));
  EXPECT_EQ(1, factorial(1));
  EXPECT_EQ(2, factorial(2));
  EXPECT_EQ(6, factorial(3));
  EXPECT_EQ(24, factorial(4));
  EXPECT_EQ(120, factorial(5));
}


