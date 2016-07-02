#include <gtest/gtest.h>
#include <iostream>
#include <string>
#include "copy.cc"

using namespace std;

TEST(Copy, copy) {
    Base b("Fletch");
    EXPECT_EQ("Fletch", b.name()) << "Normal assignement should succeed";
    EXPECT_EQ(1, b.instances()) << "1 instance should have been created";
}

