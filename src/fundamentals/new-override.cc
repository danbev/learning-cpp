#include <cstddef>
#include <iostream>

class Something {
 public:
  Something(int x) : x_(x) {
    std::cout << "Something constructor: x=" << x << '\n';
  }
  ~Something() {
    std::cout << "Something destructor" <<  '\n';
  }

  void* operator new(size_t size) {
    std::cout << "Overridden operartor new. size: " << size << '\n';
    return malloc(size);
  }
  void operator delete(void* ptr) {
    std::cout << "Overridden operartor delete. ptr: " << ptr << '\n';
    free(ptr);
  }

  private:
   int x_;
};

int main(int argc, char** argv) {
  // The overloaded operator are only used for this specific class.
  Something* s1 = new Something{5};
  delete s1;

  // The following will use the default operators new and delete.
  int* i = new int;
  delete i;

  return 0;
}
