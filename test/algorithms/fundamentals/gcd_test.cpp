#include <gtest/gtest.h>
#include "gcd.cpp"

TEST(gcd, sixAndTwelve) {
  EXPECT_EQ(6, gcd(6, 12));
}

TEST(gcd, twelveAndEight) {
  EXPECT_EQ(4, gcd(12, 8));
}

TEST(gcd, large) {
  EXPECT_EQ(6, gcd(54, 888));
}

