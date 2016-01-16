#include <gtest/gtest.h>
#include "bu_mergesort.cpp"

TEST(BottomUpMergesort, sort) {
  int unsorted[] = {2, 4, 1, 5, 3};
  int len = 5;
  int *sorted = mergesort(unsorted, len);
  EXPECT_EQ(1, sorted[0]);
  EXPECT_EQ(2, sorted[1]);
  EXPECT_EQ(3, sorted[2]);
  EXPECT_EQ(4, sorted[3]);
  EXPECT_EQ(5, sorted[4]);
}
