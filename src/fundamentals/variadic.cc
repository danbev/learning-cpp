#include <iostream>

template<typename T>
T adder(T v) {
  std::cout << __PRETTY_FUNCTION__ << "\n";
  return v;
}

template<typename T, typename... Args>
T adder(T first, Args... args) {
  std::cout << __PRETTY_FUNCTION__ << "\n";
  return first + adder(args...);
  // notice the recursive call above, the first arg will always end up in first
  // and eventually adder that takes a single argument will be called, and then
  // the callstack will return a
}

// $ clang++ -Xclang -fdump-record-layouts variadic.cc
int main(int argc, char** argv) {
  long sum = adder(1, 2, 3, 4);
  std::cout << sum << '\n';
}
