#include <gtest/gtest.h>
#include <iostream>
#include "bst.cpp"

TEST(BinarySearchTree, getMissingKey) {
  BinarySearchTree bts;
  try {
    bts.get(10);
  } catch (const char *msg) {
    EXPECT_EQ("No such key", msg);
  }
}

TEST(BinarySearchTree, getSingleValue) {
  BinarySearchTree bts;
  bts.put(1, 'z');
  EXPECT_EQ('z', bts.get(1));
}

TEST(BinarySearchTree, put) {
  BinarySearchTree bts;
  bts.put(1, 'z');
  bts.put(2, 'b');
  EXPECT_EQ('z', bts.get(1));
  EXPECT_EQ('b', bts.get(2));
}

TEST(BinarySearchTree, sizeEmpty) {
  BinarySearchTree bts;
  EXPECT_EQ(0, bts.size());
}

TEST(BinarySearchTree, size) {
  BinarySearchTree bts;
  bts.put(1, 'z');
  bts.put(2, 'a');
  EXPECT_EQ(2, bts.size());
}
