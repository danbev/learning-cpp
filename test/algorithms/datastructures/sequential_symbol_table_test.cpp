#include <gtest/gtest.h>
#include <iostream>
#include "sequential-symbol-table.cpp"

TEST(SequentialSymbolTable, put) {
    SequentialSymbolTable sst = SequentialSymbolTable();
    sst.put(10, 'a');
    sst.put(1, 'b');
    sst.put(2, 'x');
    EXPECT_EQ('a', sst.get(10));
}
