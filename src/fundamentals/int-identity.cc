#include <iostream>

template <int X>
struct IntIdentity {
  static constexpr int value = X;
};

int main(int argc, char** argv) {
  int v = IntIdentity<18>::value;
  std::cout << "v: " << v << '\n';
  
  return 0;
}
