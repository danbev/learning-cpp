#include "pimpl.h"
#include <iostream>

// $ clang++ -std=c++14 -I. pimpl.cc pimpl_usage.cc -o pimpl
int main(int argc, char** argv) {
  std::string name = "Fletch";
  Pimpl p {name};
  std::cout << p.message() << '\n';
  return 0;
}
