#include <iostream>
#include <gtest/gtest.h>
#include "queue.cpp"

TEST(Queue, addIntValueToEmptyList) {
  Queue queue;
  queue.enqueue(1);
  EXPECT_EQ(1, queue.dequeue());
}

TEST(Queue, addIntValueTo) {
  Queue queue;
  queue.enqueue(1).enqueue(2).enqueue(10);
  EXPECT_EQ(3, queue.size());
  EXPECT_EQ(1, queue.dequeue());
  EXPECT_EQ(2, queue.dequeue());
  EXPECT_EQ(10, queue.dequeue());
}

TEST(Queue, popEmptyList) {
  Queue queue;
  EXPECT_EQ(-1, queue.dequeue());
}

