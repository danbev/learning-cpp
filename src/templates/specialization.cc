#include <iostream>

template <typename T>
struct something {
  T member;
};

template<>
struct something<bool> {
  bool member;
};

int main(int argc, char** argv) {
  std::cout << "main..." << '\n';
  struct something<int> int_something{4};
  std::cout << "int_something: " << int_something.member << '\n';

  return 0;
}
