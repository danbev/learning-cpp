#include <gtest/gtest.h>
#include <iostream>
#include "visibility.cc"

using namespace std;

TEST(Visibility, doitPublic) {
  Visibility v;
  EXPECT_EQ("public", v.doitPublic());
  EXPECT_EQ("private", v.doitPrivate());
}

