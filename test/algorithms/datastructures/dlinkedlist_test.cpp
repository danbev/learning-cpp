#include <iostream>
#include <gtest/gtest.h>
#include "dlinkedlist.cpp"

TEST(dlinkedlist, end) {
  DLinkedList list;
  EXPECT_EQ(10, list.addFront(10).end());
}

TEST(dlinkedlist, addEnd) {
  DLinkedList list;
  EXPECT_EQ(1, list.addEnd(22).size());
  EXPECT_EQ(22, list.end());
}

TEST(dlinkedlist, removeEnd) {
  DLinkedList list;
  EXPECT_EQ(22, list.addEnd(22).removeEnd());
}

TEST(dlinkedlist, contains) {
  DLinkedList list;
  EXPECT_EQ(false, list.contains(1));
  list.addFront(1);
  EXPECT_EQ(true, list.contains(1));
  EXPECT_EQ(false, list.contains(2));
}

void printInt(int i) {
  std::cout << i << std::endl;
}

TEST(DlinkedList, forEach) {
  DLinkedList list;
  list.addEnd(1).addEnd(2).addEnd(3);
  list.forEach(printInt);
}

