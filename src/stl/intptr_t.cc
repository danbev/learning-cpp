#include <stdint.h>
#include <iostream>

struct something {
  int x = 10;
};

int main(int argc, char** argv) {
  intptr_t i = intptr_t{1} + 9;
  struct something* s = reinterpret_cast<something*>(i);
  std::cout << i << '\n';
  std::cout << s->x << '\n';
  return 0;
}
