#include <gtest/gtest.h>
#include "lcg.cpp"
#include <iostream>

TEST(lcg, generate) {
  LCG lcg (0);
  EXPECT_EQ(3, lcg.generate());
  std::cout << lcg << std::endl;
  EXPECT_EQ(4, lcg.generate());
  std::cout << lcg << std::endl;
  EXPECT_EQ(2, lcg.generate());
  std::cout << lcg << std::endl;
  EXPECT_EQ(6, lcg.generate());
  std::cout << lcg << std::endl;
  EXPECT_EQ(5, lcg.generate());
  std::cout << lcg << std::endl;
  EXPECT_EQ(0, lcg.generate());
  std::cout << lcg << std::endl;
}

