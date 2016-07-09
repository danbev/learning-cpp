#include <gtest/gtest.h>
#include <iostream>
#include <utility>
#include <string>
#include "ambig.cc"

using namespace std;

TEST(Ambig, example) {
  Base a("Fletch");
  Derived b("Rosen");
  EXPECT_EQ(1, a.handle());
  EXPECT_EQ('b', b.handle());
  EXPECT_EQ(1, b.handleFromBase());
}

