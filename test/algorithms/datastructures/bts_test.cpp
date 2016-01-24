#include <gtest/gtest.h>
#include <iostream>
#include "bts.cpp"

TEST(BinarySearchTree, getMissingKey) {
  BinarySearchTree bts;
  try {
    bts.get(10);
  } catch (const char *msg) {
    EXPECT_EQ("No such key", msg);
  }
}
