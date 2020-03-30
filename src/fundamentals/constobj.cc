#include <iostream>

class Something {
 public:
   void doit() const {
     std::cout << "const doing it...\n";
   }
   void doit() {
     std::cout << "non-const doing it...\n";
   }

};

int main(int argc, char** argv) {
  Something s;
  s.doit();
  const Something s2;
  s2.doit();
  return 0;
}
