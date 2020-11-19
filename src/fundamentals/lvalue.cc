#include <iostream>

int& value() {
  static int v = 18;
  return v;
}

int main(int argc, char** argv) {
  std::cout << "value: " << value() << '\n';
  value() = 20;
  std::cout << "value: " << value() << '\n';
  return 0;
}
