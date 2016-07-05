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
    const int a = 10;
    const int *b = &a;
    EXPECT_EQ(10, a);
    EXPECT_EQ(10, *b);
}

TEST(consts, constPointer) {
    int a = 10;
    int b = 20;
    EXPECT_EQ(10, a);
    EXPECT_EQ(20, b);
    a = 30;
    int * const c = &a;
    EXPECT_EQ(30, *c);
    *c = 40;
    EXPECT_EQ(40, *c) << "Should be able to assign to the int";
}
