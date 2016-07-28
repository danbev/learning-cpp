#include <gtest/gtest.h>
#include <iostream>
#include <typeinfo>
#include "macros.cc"

using namespace std;

TEST(MacroExample, macro) {
    MacroExample m {};
    EXPECT_EQ("test:private_symbol", m.test_private_symbol());
    EXPECT_EQ("test:private_symbol2", m.test_private_symbol2());
}
