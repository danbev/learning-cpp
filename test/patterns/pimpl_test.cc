#include <gtest/gtest.h>
#include <iostream>
#include "pimpl.h"

using namespace std;

TEST(Pimpl, basic) {
  Pimpl p("testing");
  std::string m = p.message();
  std::cout << m << '\n';
  //EXPECT_EQ("public", v.doitPublic());
  //EXPECT_EQ("private", v.doitPrivate());
}

