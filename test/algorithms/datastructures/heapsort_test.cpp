#include <gtest/gtest.h>
#include "heapsort.cpp"

TEST(HeapSort, sort) {
  HeapSort hs;
  char a[] = {'b', 't', 'z', 'a', 'r'};
  hs.sort(a, 5);
  EXPECT_EQ('a', a[0]);
  EXPECT_EQ('b', a[1]);
  EXPECT_EQ('r', a[2]);
  EXPECT_EQ('t', a[3]);
  EXPECT_EQ('z', a[4]);
}

