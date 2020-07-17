#include <iostream>

void doit(int x) {
  std::cout << "doit: " << x << '\n';
}

void doit2(int x) {
  std::cout << "doit2: " << x << '\n';
}

int main(int argc, char** argv) {
  void (*d)(int);
  d = &doit;
  d(10);
  d = &doit2;
  d(10);
  std::cout << "address of doit: " << reinterpret_cast<void*>(doit) << '\n';
  std::cout << "address of doit2: " << reinterpret_cast<void*>(doit2) << '\n';
  return 0;
}
