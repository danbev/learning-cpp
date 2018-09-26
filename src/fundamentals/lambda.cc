#include <iostream>
#include <functional>

struct OnScopeLeave {
  std::function<void()> fn_;

  explicit OnScopeLeave(std::function<void()> fn) : fn_(fn) {}
  ~OnScopeLeave() { fn_(); }
};

// $ clang++ -std=c++11 -o lambda lambda.cc

int main(int argc, char** argv) {
  int s = 0;
  std::cout << "lambda..." << '\n';
  {
    OnScopeLeave cleanup([&s] {
        std::cout << "cleanup...s=" << s << '\n';
    });
    s = 10;
  }
  return 0;
}
