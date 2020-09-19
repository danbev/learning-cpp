#include <iostream>

namespace {
  // Field in anonymous namespace
  class Base {
    public:
      Base() {
        std::cout << "Base in object-linkage.h\n";
      }
  };
}

// This class is not in the anonymous namespace
class Something : public Base {
 public:
   int nr;
};
