#include <gtest/gtest.h>
#include <iostream>
#include "pimpl.h"

using namespace std;

TEST(Pimpl, message) {
  Pimpl p("testing");
  std::string m = p.message();
  EXPECT_EQ("testing", p.message());
}
