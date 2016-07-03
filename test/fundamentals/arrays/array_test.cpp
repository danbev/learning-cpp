#include <gtest/gtest.h>
#include <iostream>

using namespace std;

TEST(Array, initialize) {
  int arr[2] = {1, 2};
  int arr2[] = {1, 2};
  EXPECT_EQ(arr[0], 1);
  EXPECT_EQ(arr2[0], 1);
}

