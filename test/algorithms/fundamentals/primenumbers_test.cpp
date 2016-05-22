#include <iostream>
#include <gtest/gtest.h>
#include "primenumbers.cpp"

TEST(primefactors, 3) {
  LinkedList<int> stack = primefactors(3);
  EXPECT_EQ(3, stack.removeFront());
}

TEST(primefactors, 10) {
  LinkedList<int> stack = primefactors(10);
  EXPECT_EQ(5, stack.removeFront());
  EXPECT_EQ(2, stack.removeFront());
}

TEST(primefactors, 8) {
  LinkedList<int> stack = primefactors(8);
  EXPECT_EQ(2, stack.removeFront());
  EXPECT_EQ(2, stack.removeFront());
}

TEST(primefactors, 315) {
  LinkedList<int> stack = primefactors(315);
  EXPECT_EQ(7, stack.removeFront());
  EXPECT_EQ(5, stack.removeFront());
  EXPECT_EQ(3, stack.removeFront());
  EXPECT_EQ(3, stack.removeFront());
}
