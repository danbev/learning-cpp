#include <gtest/gtest.h>
#include <iostream>
#include "bst.cpp"

TEST(BinarySearchTree, getMissingKey) {
  BinarySearchTree bts = BinarySearchTree();
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

TEST(BinarySearchTree, min) {
  BinarySearchTree bts;
  bts.put(1, 'a');
  bts.put(2, 'z');
  EXPECT_EQ('a', bts.min());
}

TEST(BinarySearchTree, max) {
  BinarySearchTree bts;
  bts.put(1, 'a');
  bts.put(2, 'b');
  bts.put(3, 'c');
  bts.put(4, 'd');
  EXPECT_EQ('d', bts.max());
}
