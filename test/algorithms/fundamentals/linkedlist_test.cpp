#include <gtest/gtest.h>
#include "linkedlist.cpp"


TEST(linkedlist, addIntValueToEmptyList) {
  LinkedIntList list;
  list.push(1);
  EXPECT_EQ(1, list.pop());
}

TEST(linkedlist, addIntValueTo) {
  LinkedIntList list;
  list.push(1).push(2).print();
  EXPECT_EQ(2, list.pop());
  EXPECT_EQ(1, list.pop());
}

TEST(linkedlist, popEmptyList) {
  LinkedIntList list;
  EXPECT_EQ(0, list.pop());
}

