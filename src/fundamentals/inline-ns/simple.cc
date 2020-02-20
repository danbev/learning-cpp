#include <iostream>

namespace something {
  void ns_function() {
    std::cout << "ns_function" << '\n';
  }
}

inline namespace inline_something {
  void inner_ns_function() {
    std::cout << "inner_ns_function" << '\n';
  }
}

int main(int argc, char** argv) {
  something::ns_function();
  inline_something::inner_ns_function();

  inner_ns_function();
  return 0;
}
