#include <gtest/gtest.h>
#include <iostream>
#include <typeinfo>
#include "util.cc"

using namespace std;

class In {
  public:
    int age = 10;
};

template <typename T>
class Out {
  public:
    T in;
    int two;
};


TEST(Util, cast) {
  std::cout << sizeof(Out<int>) << std::endl;
  int* n = static_cast<int*>(0);
  EXPECT_EQ(nullptr, n);

  Out<In>* o = static_cast<Out<In>*>(0);
  EXPECT_EQ(nullptr, o);
  int Out<In>::*twoptr = &Out<In>::two;
  int* iptr = &(o->*twoptr);
  EXPECT_EQ(4, reinterpret_cast<uintptr_t>(iptr));
  // so we can see that we can get the address of the member two

  In in {};
  Out<In>* out = ContainerOf(&Out<In>::in, &in);
  EXPECT_EQ(10, out->in.age);
}

