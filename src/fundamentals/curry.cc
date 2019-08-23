#include <iostream>

int main(int argc, char** argv) {
  const char* b = "b";
  auto add = [&b](int x, char ch) {
    return [=] (int y) {
      return y + x;
    };
  };
  auto add_two = add(2, 'c');
  std::cout << add_two(10) << '\n';

  return 0;
}
