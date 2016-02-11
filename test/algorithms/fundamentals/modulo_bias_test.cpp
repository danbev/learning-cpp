#include <gtest/gtest.h>
#include <iostream>

TEST(modulo, bias) {
  int m = 3; // we are only interested in values in the range 0-2
  int random[5] = {0, 1, 2, 3, 4};
  int zeroCounter = 0;
  int oneCounter = 0;
  int twoCounter = 0;
  EXPECT_EQ(0, random[0] % m);
  zeroCounter++;
  EXPECT_EQ(1, random[1] % m);
  oneCounter++;
  EXPECT_EQ(2, random[2] % m);
  twoCounter++;
  EXPECT_EQ(0, random[3] % m);
  zeroCounter++;
  EXPECT_EQ(1, random[4] % m);
  oneCounter++;
  EXPECT_EQ(2, zeroCounter);
  EXPECT_EQ(2, oneCounter);
  EXPECT_EQ(1, twoCounter);
  // notice that we only get 2 once. We have five entries in our "random" array
  // Why are we getting this uneven distribution. The size of our output set, 3 
  // is not evenly divisable by the input set 5
  std::cout << 2 % m << std::endl;
}

TEST(modulo, evenDistribution) {
  int m = 3; 
  int random[6] = {0, 1, 2, 3, 4, 5}; // output size is evenly divisable with input size
  int zeroCounter = 0;
  int oneCounter = 0;
  int twoCounter = 0;
  EXPECT_EQ(0, random[0] % m);
  zeroCounter++;
  EXPECT_EQ(1, random[1] % m);
  oneCounter++;
  EXPECT_EQ(2, random[2] % m);
  twoCounter++;
  EXPECT_EQ(0, random[3] % m);
  zeroCounter++;
  EXPECT_EQ(1, random[4] % m);
  oneCounter++;
  EXPECT_EQ(2, random[5] % m);
  twoCounter++;

  EXPECT_EQ(2, zeroCounter);
  EXPECT_EQ(2, oneCounter);
  EXPECT_EQ(2, twoCounter);
}

