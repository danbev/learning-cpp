#include <gtest/gtest.h>
#include <iostream>
#include <string>
#include "copy.cc"

using namespace std;

TEST(Copy, copy) {
  {
    Base a("Fletch");
    // will invoke copy constructor
    Base b = a;
  }
  EXPECT_EQ(1, Base::instances()) << "Constructor should have been called once";
  EXPECT_EQ(1, Base::copied()) << "Copy constructor called for b = a";
  EXPECT_EQ(2, Base::destroyed()) << "Destructor should have been called twice";
}

