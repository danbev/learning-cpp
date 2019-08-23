#include <iostream>

bool f() {
  return nullptr;
}

int main(int arg, char** argv) {
  std::cout << "return nullptr for bool value..." << '\n';
  std::cout << f() << '\n';
}
