#include <gtest/gtest.h>
#include <iostream>
#include <string>
#include "sequential-symbol-table.cpp"

TEST(SequentialSymbolTable, put) {
    SequentialSymbolTable<int, char> sst = SequentialSymbolTable<int, char>();
    sst.put(10, 'a');
    sst.put(1, 'b');
    sst.put(2, 'x');
    EXPECT_EQ('a', sst.get(10)) << "Value at index 10 should have been " << 'a';
}

TEST(SequentialSymbolTable, stringKeys) {
    SequentialSymbolTable<std::string, char> sst = SequentialSymbolTable<std::string, char>();
    sst.put("one", 'a');
    sst.put("two", 'b');
    sst.put("thre", 'x');
    EXPECT_EQ('a', sst.get("one")) << "Value for key 'one' should have been " << 'a';
}
