#include <iostream>

// $ clang++ -g -o deref deref.cc
class Test {
 public:
  Test() {
  std::cout << "Test()" << '\n';
  }
  ~Test() {
  std::cout << "~Test()" << '\n';
  }
  int doit() {
   return 18; 
  }
};

int main(int argc, char** argv) {
  Test* t = nullptr;
  std::cout << t->doit() << '\n';
}
