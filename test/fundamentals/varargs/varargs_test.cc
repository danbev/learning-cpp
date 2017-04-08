#include <gtest/gtest.h>
#include <iostream>
#include "varargs.cc"

using namespace std;

TEST(varargs, test) {
  Args a = {"prog", "one", "two", "three"};
  EXPECT_EQ(a.size(), 4);
  EXPECT_EQ(a.name(), "prog");
  auto it = a.ls().begin();
  EXPECT_EQ(*it, "one");
  ++it;
  EXPECT_EQ(*it, "two");
  ++it;
  EXPECT_EQ(*it, "three");
}
