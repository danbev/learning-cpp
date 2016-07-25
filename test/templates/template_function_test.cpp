#include <gtest/gtest.h>
#include <iostream>
#include <string>
#include "template-function.cc"

using namespace std;

TEST(TemplateFunction, function) {
  Testing t;
  void (*printit)(int) = Testing::doit<int>;
  // the template parameters can be explicit
  t.doit<int>(10);
  // the template parameters can be empty
  t.doit<>("bajja");
  // the template parameters or left out
  t.doit("bajja");
  printit(22);
  //EXPECT_EQ(3, Base::destroyed()) << "Destructor should have been called three times";
}

