#include <iostream>

struct some_struct {
  int nr = 20;
};

class Something {
 public:
   Something(const some_struct& s) {
     std::cout << "s.nr=" << s.nr << '\n';
   }
};

int main(int argc, char** argv) {
  struct some_struct s{};
  Something s1{s};
  Something s2{{}};
  // the above is the same as:
  const some_struct& y = {};
  std::cout << "y.nr=" << y.nr << '\n';
  return 0;
}
