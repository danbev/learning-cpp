// $ clang++ -o auto.o auto.cc --std=c++11
#include <iostream>
#include <cassert>

int main() {
  int x = 10;
  const int& y = x;
  assert(x = y);
  // Can't assign to const int y
  //y = 20;

  // Type of z will be int
  // * The reference is ignored
  // * const/volatile is ignored
  auto z = y;
  assert(x = z);
  z = 20;

  // using auto& will keep the const int& type.
  auto& w = y;
  //w = 20;

  int i = 18;
  auto&& r1 = i;
  auto&& r2 = 18;

}
