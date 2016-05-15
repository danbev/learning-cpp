#include <iostream>
#include <gtest/gtest.h>
#include "bag.cpp"

TEST(Bag, add) {
  Bag bag {};
  bag.add(1).add(2);
  EXPECT_EQ(2, bag.size());
}

void printInt(int i) {
  std::cout << i << std::endl;
}

TEST(Bag, foreach) {
  Bag bag {};
  bag.add(1).add(2).add(10);
  bag.foreach(printInt);
  EXPECT_EQ(3, bag.size());
}

TEST(Bag, iterator) {
  Bag bag {};
  bag.add(1).add(2).add(10);
  EXPECT_EQ(3, bag.size());
  Iterator<int>* it = bag.iterator();
  while (it->hasNext()) {
      std::cout << it->next() << std::endl;
  }
}

