#include <gtest/gtest.h>
#include <iostream>
#include <string>

using namespace std;

template<typename T>
void f(T& param) {
  cout << "f param:" << param << '\n';
}

TEST(Refs, reference) {
  string a = "a";
  string &b = a;
  EXPECT_EQ(&a, &b);
  cout << "&a = " << &a << '\n';
  cout << "&b = " << &b << '\n';
  // notice that this r1 will be a copy even though b is a reference
  auto r1 = b;
  EXPECT_NE(&b, &r1);
  cout << "r1 = " << &r1 << '\n';

  auto& r2 = b;
  cout << "r2 = " << &r2 << '\n';
  EXPECT_EQ(&b, &r2);
  f(b); 
  //EXPECT_EQ(10, a);
  //EXPECT_EQ(10, b);
}
