#include <iostream>

template<typename T, char C>
struct SomeType {
  using type = T;
};

int main(int argc, char** argv) {
  SomeType<int, 'c'>::type v = 18;
  std::cout << "v: " << v << '\n';
  return 0;
}
