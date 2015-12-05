#include <gtest/gtest.h>
#include "quicksort_header.hpp"

TEST(quicksort_sort, one) {
  int unsorted[] = {2, 4, 1, 5, 3};
  int len = 5;
  EXPECT_EQ(1, quick_sort(unsorted, len)[0]);
  EXPECT_EQ(2, quick_sort(unsorted, len)[1]);
  EXPECT_EQ(3, quick_sort(unsorted, len)[2]);
  EXPECT_EQ(4, quick_sort(unsorted, len)[3]);
  EXPECT_EQ(5, quick_sort(unsorted, len)[4]);
}
