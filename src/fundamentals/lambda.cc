#include <iostream>
#include <functional>

struct OnScopeLeave {
  std::function<void()> fn_;

  explicit OnScopeLeave(std::function<void()> fn) : fn_(fn) {}
  ~OnScopeLeave() { fn_(); }
};

// $ clang++ -std=c++11 -o lambda lambda.cc

int main(int argc, char** argv) {
  int ret = 0;
  std::cout << "lambda..." << '\n';
  {
    OnScopeLeave cleanup([&ret] {
        std::cout << "ret = " << ret << '\n';
        if (!ret) {
          std::cout << "cleanup..." << '\n';
        } else {
          std::cout << "no cleanup" << '\n';
        }
    });
    ret = 1;
  }
  /*
  ret = 0;
  bool b = ret;
  std::cout << std::boolalpha;
  std::cout << "b = " << b << '\n';
  std::cout << "b = " << !b << '\n';
  */
  return 0;
}
