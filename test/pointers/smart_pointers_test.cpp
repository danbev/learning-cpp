#include <gtest/gtest.h>
#include <iostream>
#include "smart-pointers.cpp"

TEST(SmartPointers, autoPointer) {
    std::auto_ptr<std::string> str = autoPointer();
    std::auto_ptr<std::string> str2;
    EXPECT_EQ("bajja", *str) << "auto_ptr should be able to be dereferenced like a normal pointer";
    {
        str2 = str;
    }
    EXPECT_EQ("bajja", *str2);
    EXPECT_EQ(nullptr, str.get()) << " str one has given up ownership";
}

TEST(SmartPointers, uniquePointer) {
    std::unique_ptr<std::string> str = uniquePointer();
    std::unique_ptr<std::string> str2;
    EXPECT_EQ("bajja", *str) << "unique_ptr should be able to be dereferenced like a normal pointer";
    str2 = std::move(str);
    EXPECT_EQ("bajja", *str2) << "unique_ptr should be movable to another pointer with out a compile time error";
}
