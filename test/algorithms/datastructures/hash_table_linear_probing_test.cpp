#include <iostream>
#include <gtest/gtest.h>
#include "hash-table-linear-probing.cpp"

TEST(HashTable, size) {
  HashTable t {10};
  EXPECT_EQ(10, t.getSize());
}

TEST(HashTable, put) {
  HashTable t {10};
  t.put(1, 'a');
  t.put(2, 'b');
  t.put(11, 'd');
  t.put(11, 'd');
  t.put(24, 'f');
  EXPECT_EQ('a', t.get(1));
  EXPECT_EQ('f', t.get(24));
  EXPECT_EQ(-1, t.get(25));
}

