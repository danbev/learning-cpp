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

TEST(linkedlist, reverseArray) {
  int arr[] {1, 2, 3, 4};
  reverseArray(arr, 4);
  EXPECT_EQ(4, arr[0]);
  EXPECT_EQ(3, arr[1]);
  EXPECT_EQ(2, arr[2]);
  EXPECT_EQ(1, arr[3]);
}

