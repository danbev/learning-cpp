#include <gtest/gtest.h>
#include "bubblesort.hpp"

TEST(bubblesort, one) {
  int unsorted[] = {2, 4, 1, 5, 3};
  int len = 5;
  int * sorted = bubble_sort(unsorted, len);
  EXPECT_EQ(1, sorted[0]);
  EXPECT_EQ(2, sorted[1]);
  EXPECT_EQ(3, sorted[2]);
  EXPECT_EQ(4, sorted[3]);
  EXPECT_EQ(5, sorted[4]);
}

