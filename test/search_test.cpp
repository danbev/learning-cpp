#include <gtest/gtest.h>

#include "search.hpp"

int arr[] = {1, 2, 3, 4, 5};

TEST(binarysearch, one) {
  EXPECT_EQ(0, binarysearch(arr, 5, 1));
}

TEST(binarysearch, two) {
  EXPECT_EQ(1, binarysearch(arr, 5, 2));
}

TEST(binarysearch, three) {
  EXPECT_EQ(2, binarysearch(arr, 5, 3));
}

TEST(binarysearch, four) {
  EXPECT_EQ(3, binarysearch(arr, 5, 4));
}

TEST(binarysearch, five) {
  EXPECT_EQ(4, binarysearch(arr, 5, 5));
}

TEST(binarysearch, six) {
  EXPECT_EQ(-6, binarysearch(arr, 5, 6));
}

