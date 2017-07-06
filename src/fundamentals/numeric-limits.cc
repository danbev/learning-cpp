// $ clang++ -o numeric-limits -std=c++11 numeric-limits.cc
#include <limits>
#include <iostream>

class Something {
};

namespace std {
  template<> class numeric_limits<Something> {
    public:
      static constexpr bool is_specialized = true;
  };
}

int main(int argc, char* argv[]) {
  bool something = std::numeric_limits<Something>::is_specialized;
  bool string = std::numeric_limits<std::string>::is_specialized;
  std::cout << (something ? "true" : "false") << '\n';
  std::cout << (string ? "true" : "false") << '\n';
  return 0;
}
