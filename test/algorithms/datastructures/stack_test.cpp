#include <iostream>
#include <gtest/gtest.h>
#include "stack.cpp"


TEST(Stack, addIntValueToEmptyList) {
  Stack stack;
  stack.push(1);
  EXPECT_EQ(1, stack.pop());
}

TEST(Stack, addIntValueTo) {
  Stack stack;
  stack.push(1).push(2).print();
  EXPECT_EQ(2, stack.size());
  EXPECT_EQ(2, stack.pop());
  EXPECT_EQ(1, stack.pop());
}

TEST(Stack, popEmptyList) {
  Stack stack;
  EXPECT_EQ(-1, stack.pop());
}

/*
TEST(linkedlist, reverseArray) {
  int arr[] {1, 2, 3, 4};
  reverseArray(arr, 4);
  EXPECT_EQ(4, arr[0]);
  EXPECT_EQ(3, arr[1]);
  EXPECT_EQ(2, arr[2]);
  EXPECT_EQ(1, arr[3]);
}
*/

void printTowers(int move, Stack one, Stack two, Stack three) {
  std::cout << "Move: " << move << std::endl;
  std::cout << "Tower 1: ";
  one.print();
  std::cout << "Tower 2: ";
  two.print();
  std::cout << "Tower 3: ";
  three.print();
}

TEST(linkedlist, tower) {
  Stack peg1;
  Stack peg2;
  Stack peg3;
  peg1.push(3);
  peg1.push(2);
  peg1.push(1);
  printTowers(1, peg1, peg2, peg3);

  peg2.push(peg1.pop());
  printTowers(2, peg1, peg2, peg3);

  peg3.push(peg1.pop());
  printTowers(3, peg1, peg2, peg3);
  peg3.push(peg2.pop());
  printTowers(4, peg1, peg2, peg3);

  peg2.push(peg1.pop());
  printTowers(5, peg1, peg2, peg3);

  peg1.push(peg3.pop());
  printTowers(6, peg1, peg2, peg3);
  peg2.push(peg3.pop());
  printTowers(7, peg1, peg2, peg3);
  peg2.push(peg1.pop());
  printTowers(7, peg1, peg2, peg3);
  EXPECT_EQ(1, peg2.pop());
  EXPECT_EQ(2, peg2.pop());
  EXPECT_EQ(3, peg2.pop());
}
