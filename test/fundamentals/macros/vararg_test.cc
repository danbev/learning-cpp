#include <gtest/gtest.h>
#include <iostream>
#include <typeinfo>
#include "vararg.cc"

using namespace std;

TEST(VarArgExample, vararg) {
    VarArgExample m {"Fletch"};
    int nr = m.useMacro();
    EXPECT_EQ("Fletch", m.name());
    EXPECT_EQ(10, nr);
}
