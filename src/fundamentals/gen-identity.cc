#include <iostream>

template <typename T, T V>
struct ValueIdentity {
  static constexpr T value = V;
};

int main(int argc, char** argv) {
  int x = ValueIdentity<int, 18>::value;
  std::cout << "x: " << x << '\n';

  char c = ValueIdentity<char, 'c'>::value;
  std::cout << "c: " << c << '\n';

  return 0;
}
