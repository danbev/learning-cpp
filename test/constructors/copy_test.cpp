#include <gtest/gtest.h>
#include <iostream>
#include <string>
#include "copy.cc"

using namespace std;

TEST(Copy, copy) {
  {
    Base a("Fletch");
    Base b = a;
  }
  EXPECT_EQ(1, Base::instances()) << "1 instance should have been created";
  EXPECT_EQ(2, Base::destroyed()) << "1 instance should have been created";
}

