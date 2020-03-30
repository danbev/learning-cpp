#include <string>
#include <iostream>

#define LIST(v)    \
  v(one)           \
  v(two)           \
  v(three)

enum class Roots {
#define INC(...) + 1
  count = 0 LIST(INC),
};

int main(int argc, char** argv) {
  std::cout << (int) Roots::count << '\n';
  return 0;
}

