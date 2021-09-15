#include <iostream>

template<typename T>
struct SomeValue {
  static constexpr T value = 18;
};

int main(int argc, char** argv) {
  int v = SomeValue<int>::value;
  std::cout << "v: " << v << '\n';
  return 0;
}
