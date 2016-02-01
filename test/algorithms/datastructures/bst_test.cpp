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

TEST(BinarySearchTree, floor) {
  BinarySearchTree bts;
  bts.put(1, 'a');
  bts.put(2, 'b');
  bts.put(4, 'd');
  EXPECT_EQ(4, bts.floor(5));
  EXPECT_EQ(4, bts.floor(4));
  EXPECT_EQ(2, bts.floor(3));
}

TEST(BinarySearchTree, ceil) {
  BinarySearchTree bts;
  bts.put(2, 'b');
  bts.put(4, 'd');
  EXPECT_EQ(2, bts.ceil(1));
}

TEST(BinarySearchTree, rank) {
  BinarySearchTree bts;
  bts.put(1, 'a');
  bts.put(2, 'b');
  bts.put(3, 'c');
  bts.put(4, 'd');
  EXPECT_EQ(3, bts.rank(4));
  EXPECT_EQ(2, bts.rank(3));
  EXPECT_EQ(1, bts.rank(2));
  EXPECT_EQ(0, bts.rank(1));
}

TEST(BinarySearchTree, deleteMin) {
  BinarySearchTree bts;
  bts.put(3, '3');
  bts.put(1, '1');
  bts.put(2, '2');
  EXPECT_EQ('1', bts.min());
  EXPECT_EQ(3, bts.size());
  bts.deleteMin();
  EXPECT_EQ('2', bts.min());
  EXPECT_EQ(2, bts.size());
  bts.deleteMin();
  EXPECT_EQ('3', bts.min());
  EXPECT_EQ(1, bts.size());
}

TEST(BinarySearchTree, deleteMax) {
  BinarySearchTree bts;
  bts.put(3, '3');
  bts.put(1, '1');
  bts.put(2, '2');
  EXPECT_EQ('3', bts.max());
  bts.deleteMax();
  EXPECT_EQ('2', bts.max());
  bts.deleteMax();
  EXPECT_EQ('1', bts.max());
}

TEST(BinarySearchTree, deleteKey) {
  BinarySearchTree bst;
  bst.put(3, '3');
  bst.put(1, '1');
  bst.put(2, '2');
  bst.deleteKey(1);
  try {
    bst.get(1);
    ASSERT_TRUE(false);
  } catch (const char *msg) {
    EXPECT_EQ("No such key", msg);
  }
}
