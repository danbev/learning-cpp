#include <gtest/gtest.h>

#include "insertionsort.hpp"

TEST(insertionsort, one) {
  int unsorted[] = {2, 4, 1, 5, 3};
  int len = 5;
  EXPECT_EQ(1, insertion_sort(unsorted, len)[0]);
  EXPECT_EQ(2, insertion_sort(unsorted, len)[1]);
  EXPECT_EQ(3, insertion_sort(unsorted, len)[2]);
  EXPECT_EQ(4, insertion_sort(unsorted, len)[3]);
  EXPECT_EQ(5, insertion_sort(unsorted, len)[4]);
}

