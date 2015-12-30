#include <gtest/gtest.h>
#include "randomize.cpp"
#include <iostream>

TEST(randomize, one) {
  int array[] = {1, 2, 3, 4, 5};
  int len = 5;
  randomize(array, len);
  std::cout << "randomized array: " << std::endl;
  for (int i = 0; i < len; i++) {
    std::cout << array[i];
  }
  std::cout << std::endl;
}

