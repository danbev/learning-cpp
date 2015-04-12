#include <gtest/gtest.h>
#include "bubblesort.hpp"

TEST(bubblesort, one) {
  int unsorted[] = {2, 4, 1, 5, 3};
  int len = 5;
  EXPECT_EQ(1, bubble_sort(unsorted, len)[0]);
  EXPECT_EQ(2, bubble_sort(unsorted, len)[1]);
  EXPECT_EQ(3, bubble_sort(unsorted, len)[2]);
  EXPECT_EQ(4, bubble_sort(unsorted, len)[3]);
  EXPECT_EQ(5, bubble_sort(unsorted, len)[4]);
}

