#include <gtest/gtest.h>
#include "binaryheap.cpp"

TEST(BinaryHeap, capacity) {
  BinaryHeap bh;
  EXPECT_EQ(10, bh.capacity());
}

TEST(BinaryHeap, insert) {
  BinaryHeap bh;
  bh.insert('a');
  EXPECT_EQ('a', bh.max());
  bh.insert('z');
  EXPECT_EQ('z', bh.max());
  bh.insert('t');
  EXPECT_EQ('z', bh.max());
  bh.insert('s');
  bh.insert('p');
  bh.insert('e');
  EXPECT_EQ(6, bh.size());
}

// a b c d e f g h i j k l m n o p q r s t v u w x y z
// a[z,t,b,a,r] :
//          1 (z)  
//           /  \
//        2(t)   3(b)
//        / \
//     4(a) 5(r)
//
TEST(BinaryHeap, take) {
  BinaryHeap bh;
  bh.insert('a');
  bh.insert('b');
  bh.insert('t');
  bh.insert('r');
  bh.insert('z');
  bh.printArray();
  EXPECT_EQ('z', bh.removeMax());
  bh.printArray();
  EXPECT_EQ('t', bh.removeMax());
  bh.printArray();
  EXPECT_EQ('r', bh.removeMax());
  bh.printArray();
  EXPECT_EQ('b', bh.removeMax());
  bh.printArray();
}

