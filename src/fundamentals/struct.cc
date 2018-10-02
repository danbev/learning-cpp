//$ clang++ struct.cc -o struct --std=c++11
#include <iostream>

struct s {
  int x = 20;
} something;

int main(int argc, char* argv[]) {
  std::cout << something.x << '\n';
  return 0;
}
