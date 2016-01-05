#include <iostream>
#include <gtest/gtest.h>
#include "primenumbers.cpp"

TEST(primefactors, 3) {
  LinkedIntList stack = primefactors(3);
  EXPECT_EQ(3, stack.pop());
}

TEST(primefactors, 10) {
  LinkedIntList stack = primefactors(10);
  EXPECT_EQ(5, stack.pop());
  EXPECT_EQ(2, stack.pop());
}

TEST(primefactors, 8) {
  LinkedIntList stack = primefactors(8);
  EXPECT_EQ(2, stack.pop());
  EXPECT_EQ(2, stack.pop());
}

TEST(primefactors, 315) {
  LinkedIntList stack = primefactors(315);
  EXPECT_EQ(7, stack.pop());
  EXPECT_EQ(5, stack.pop());
  EXPECT_EQ(3, stack.pop());
  EXPECT_EQ(3, stack.pop());
}
