#include <gtest/gtest.h>
#include <iostream>
#include <utility>
#include <string>
#include "move.cc"

using namespace std;

TEST(Move, move) {
  Base a("Fletch");
  // move turns an lvalue into an rvalue, which will cause
  // the move contructor to be called.
  Base d = std::move(a);
  // basically this is what move does:
  Base&& b = static_cast<remove_reference<decltype(a)>::type&&>(a);
  EXPECT_EQ(1, Base::instances());
  EXPECT_EQ(1, Base::moveInstances());
}

