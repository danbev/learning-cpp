#include <iostream>
#include <cstring>

class Something {
 public:
   Something(int nr) : nr_(nr) {
     std::cout << "Something constructor...nr: " << nr_ << "\n";
   }
   int nr_;
};

int main(int argc, char** argv) {
  std::cout << "operator:: new example\n";
  Something s(1);
  int size = sizeof(s);

  // note that the following will not call the constructor
  Something* s2 = reinterpret_cast<Something*>(::operator new(size));
  memcpy(s2, &s, size);

  std::cout << "s2->nr_: " << s2->nr_ << "\n";

  return 0;
}
