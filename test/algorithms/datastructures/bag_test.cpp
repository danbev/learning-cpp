#include <iostream>
#include <gtest/gtest.h>
#include "bag.cpp"

TEST(Bag, capacity) {
  Bag bag {20};
  EXPECT_EQ(20, bag.capacity());
}

TEST(Bag, add) {
  Bag bag {20};
  bag.add(1)->add(2);
  EXPECT_EQ(2, bag.size());
}

void printInt(int i) {
  std::cout << i << std::endl;
}

TEST(Bag, foreach) {
  Bag bag {20};
  bag.add(1)->add(2)->add(10);
  bag.foreach(printInt);
  EXPECT_EQ(3, bag.size());
}

