#include <iostream>

class Something1 {
 public:
  Something1() {
    std::cout << "Something1\n";
  }
 private:
  std::ios_base::Init mInitializer;
};

class Something2 {
 public:
  Something2() {
    std::cout << "Something2\n";
  }
 private:
  std::ios_base::Init mInitializer;
};

Something1 s1 __attribute__ ((init_priority (20000)));
Something2 s2 __attribute__ ((init_priority (10000)));;

int main(int argc, char** argv) {
  return 0;
}

