#include <iostream>
#include <gtest/gtest.h>
#include "binary-search.cpp"

TEST(binarysearch, search) {
    char sorted[5] = {'a', 'b', 'c', 'd', 'f'};
    int length = 5;
    EXPECT_EQ(0, binarysearch(sorted, length, 'a'));
    EXPECT_EQ(1, binarysearch(sorted, length, 'b'));
    EXPECT_EQ(2, binarysearch(sorted, length, 'c'));
    EXPECT_EQ(3, binarysearch(sorted, length, 'd'));
    EXPECT_EQ(4, binarysearch(sorted, length, 'f'));
    EXPECT_EQ(-6, binarysearch(sorted, length, 'g'));
}
