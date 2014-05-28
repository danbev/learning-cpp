#include <gtest/gtest.h>

#include "sort.hpp"

int unsorted[] = {2, 4, 1, 5, 3};
int expected[] = {1, 2, 3, 4, 5};
int len = 5;

TEST(insertionsort, one) {
  EXPECT_EQ(1, insertion_sort(unsorted, len)[0]);
  EXPECT_EQ(2, insertion_sort(unsorted, len)[1]);
  EXPECT_EQ(3, insertion_sort(unsorted, len)[2]);
  EXPECT_EQ(4, insertion_sort(unsorted, len)[3]);
  EXPECT_EQ(5, insertion_sort(unsorted, len)[4]);
}


