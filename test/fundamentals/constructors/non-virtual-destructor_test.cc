#include <gtest/gtest.h>
#include <iostream>
#include "non-virtual-destructor.cc"

using namespace std;

TEST(Default, destructor) {
  Base* b = new Derived("Jon Cocktolstol");
  EXPECT_EQ("Jon Cocktolstol", b->name());
  delete b;
  EXPECT_EQ(1, Base::instances()) << "Base constructor should have been called once";
  EXPECT_EQ(1, Base::destroyed()) << "Base destructor should have been called once";
  EXPECT_EQ(1, Derived::instances()) << "Derived constructor should have been called once";
  EXPECT_EQ(0, Derived::destroyed()) << "Derived destructor should not have been called";
}

