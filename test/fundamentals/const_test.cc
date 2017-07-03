#include <gtest/gtest.h>
#include <iostream>

using namespace std;

TEST(consts, constInt) {
  const int a = 10;
  int const b = a;
  EXPECT_EQ(10, a);
  EXPECT_EQ(10, b);
}

TEST(consts, pointerToConst) {
  int const a = 10;
  const int *b;  // pointer is not const so does not have to be initilized.
  int const *c;
  b = &a;
  c = &a;
  EXPECT_EQ(10, a);
  EXPECT_EQ(10, *b);
  EXPECT_EQ(10, *c);
}

TEST(consts, constPointer) {
    int a = 10;
    int * const c = &a;
    *c = 30;
    EXPECT_EQ(30, *c);
}

TEST(consts, constPointerToConst) {
    const int a = 10;
    const int * const b = &a;
    EXPECT_EQ(10, *b);
}
