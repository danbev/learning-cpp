#include <iostream>
#include <gtest/gtest.h>
#include "linkedlist.cpp"

TEST(Linkedlist, empty) {
  LinkedList<int> list;
  EXPECT_EQ(true, list.empty());
  list.addFront(10);
  EXPECT_EQ(false, list.empty());
}

TEST(Linkedlist, addFront) {
  LinkedList<int> list;
  list.addFront(1).addFront(2).print();
  EXPECT_EQ(2, list.size());
  EXPECT_EQ(2, list.removeFront());
  EXPECT_EQ(1, list.removeFront());
}

TEST(Linkedlist, removeFront) {
  LinkedList<int> list;
  EXPECT_EQ(-1, list.removeFront());
}

TEST(Linkedlist, contains) {
  LinkedList<int> list;
  EXPECT_EQ(false, list.contains(1));
  list.addFront(1);
  EXPECT_EQ(true, list.contains(1));
  EXPECT_EQ(false, list.contains(2));
}

/*
TEST(Linkedlist, reverseArray) {
  int arr[] {1, 2, 3, 4};
  LinkedList<int>::reverseArray(arr, 4);
  EXPECT_EQ(4, arr[0]);
  EXPECT_EQ(3, arr[1]);
  EXPECT_EQ(2, arr[2]);
  EXPECT_EQ(1, arr[3]);
}
*/

void printTowers(int move, LinkedList<int> one, LinkedList<int> two, LinkedList<int> three) {
  std::cout << "Move: " << move << std::endl;
  std::cout << "Tower 1: ";
  one.print();
  std::cout << "Tower 2: ";
  two.print();
  std::cout << "Tower 3: ";
  three.print();
}

TEST(Linkedlist, tower) {
  LinkedList<int> peg1;
  LinkedList<int> peg2;
  LinkedList<int> peg3;
  peg1.addFront(3);
  peg1.addFront(2);
  peg1.addFront(1);
  printTowers(1, peg1, peg2, peg3);

  peg2.addFront(peg1.removeFront());
  printTowers(2, peg1, peg2, peg3);

  peg3.addFront(peg1.removeFront());
  printTowers(3, peg1, peg2, peg3);
  peg3.addFront(peg2.removeFront());
  printTowers(4, peg1, peg2, peg3);

  peg2.addFront(peg1.removeFront());
  printTowers(5, peg1, peg2, peg3);

  peg1.addFront(peg3.removeFront());
  printTowers(6, peg1, peg2, peg3);
  peg2.addFront(peg3.removeFront());
  printTowers(7, peg1, peg2, peg3);
  peg2.addFront(peg1.removeFront());
  printTowers(7, peg1, peg2, peg3);
  EXPECT_EQ(1, peg2.removeFront());
  EXPECT_EQ(2, peg2.removeFront());
  EXPECT_EQ(3, peg2.removeFront());
}

TEST(Linkedlist, iterator) {
    LinkedList<int> list;
    list.addFront(1);
    list.addFront(2);
    list.addFront(3);
    EXPECT_EQ(3, list.size());
    Iterator<int>* it = list.iterator();
    while (it->hasNext()) {
        int i = it->next();
        std::cout << "next = " << i << std::endl;
    }
}
