#include <iostream>

class Something {
 public:
   Something(int x) : x_(x) {}

  int operator *() {
    return x_;
  }

  private:
   int x_;
};

int main(int argc, char** argv) {
  Something s{8};
  int x = *s;
  std::cout << x << s.operator*() <<  '\n';

  return 0;
}
