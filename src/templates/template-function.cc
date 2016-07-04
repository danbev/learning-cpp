#include <iostream>

class Testing {
  public:
    template<typename T> static void doit(T type);
    template<typename T> static void doit2();
};

template<typename T>
void Testing::doit(T type) {
  std::cout << "template function type = " <<  type << std::endl;
}
