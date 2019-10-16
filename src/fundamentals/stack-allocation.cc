#include <iostream>
#include <string.h>

// This just shows that we cannot allocate a char array on the stack
// and return a pointer to it. The value on the stack will most probably 
// get overwritten. We need to take a copy of it?
void create(char** s) {
  char ret[3] = {"12"};
  std::cout << "create ret=" << ret << '\n';
  *s = ret;
  std::cout << "create s=" << *s << '\n';
}

void create2(char* s) {
  char ret[3] = {"22"};
  strncpy(s, ret, 3);
  std::cout << "create2: s=" << s << '\n';
}

void create2(char* s, size_t s_len) {
  std::cout << "create2: s=" << s << '\n';
}

int main(int argc, char** argv) {
  std::cout << "stack allocation..." << '\n';
  char* s;
  create(&s);
  std::cout << "s=" << s << '\n';
  create2(s);
  std::cout << "s=" << s << '\n';
  return 0;
}
