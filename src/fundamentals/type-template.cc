#include <iostream>

template<typename T>
struct SomeType {
  using type = T;
};

int main(int argc, char** argv) {
  SomeType<int>::type v = 18;
  std::cout << "v: " << v << '\n';
  return 0;
}
