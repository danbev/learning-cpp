#include <gtest/gtest.h>
#include <iostream>
#include <utility>
#include <string>
#include "hiding.cc"

using namespace std;

TEST(Move, move) {
  Base a("Fletch");
  Derived b("Rosen");
  EXPECT_EQ(1, a.handle());
  EXPECT_EQ('d', b.handle());
}

