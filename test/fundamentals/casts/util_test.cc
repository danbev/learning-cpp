#include <gtest/gtest.h>
#include <iostream>
#include <typeinfo>
#include "util.cc"

using namespace std;

class In {
  public:
    int age = 10;
};

class Out {
  public:
    In* in;
    int two;
};


TEST(Util, cast) {
  In* in = new In();
  Out* out = ContainerOf<In*, Out>(&Out::in, &in);
  // alternatively use type deduction:
  //Out* out = ContainerOf(&Out::in, &in);
  EXPECT_EQ(10, out->in->age);
}

