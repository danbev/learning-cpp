#include <gtest/gtest.h>
#include <iostream>
#include "default-virtual-destructor.cc"

using namespace std;

TEST(Destructor, destructor) {
  Base* b = new Derived2("Jon Cocktolstol");
  EXPECT_EQ("Jon Cocktolstol", b->name());
  delete b;
  EXPECT_EQ(1, Base::instances()) << "Base constructor should have been called once";
  EXPECT_EQ(1, Base::destroyed()) << "Base destructor should have been called once";
  EXPECT_EQ(1, Derived::instances()) << "Derived constructor should have been called once";
  EXPECT_EQ(1, Derived::destroyed()) << "Derived destructor should have been called once";
}

