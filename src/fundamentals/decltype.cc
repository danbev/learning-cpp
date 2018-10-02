// $ clang++ -o decltype decltype.cc --std=c++11
#include <iostream>
#include <cassert>

int main() {
  int x = 10;
  decltype(x) y = 22;
}
