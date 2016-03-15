#include <iostream>
#include <gtest/gtest.h>
#include "pattern.cpp"

TEST(pattern, match) {
  char str[] = {"kalle"};
  char pattern[] = {"le"};
  EXPECT_EQ(true, contains(str, pattern));
}

/*
TEST(pattern, match2) {
  char str[] = {"kalle"};
  char pattern[] = {"ka"};
  EXPECT_EQ(true, contains(str, pattern));
}
*/

