#include <gtest/gtest.h>
#include <iostream>
#include "BinarySearchSymbolTable.cpp"

TEST(BinarySearchSymbolTable, put) {
    BinarySearchSymbolTable bst = BinarySearchSymbolTable(10);
    bst.put(0, 'a').print();
    bst.put(2, 'c').print();
    bst.put(1, 'b').print();
    EXPECT_EQ('a', bst.get(0));
    EXPECT_EQ('b', bst.get(1));
    EXPECT_EQ('c', bst.get(2));
}
