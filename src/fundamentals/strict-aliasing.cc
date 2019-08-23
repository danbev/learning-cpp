#include <iostream>

// $ clang++ -02-std=c++11 -o strict strict-aliasing.cc
//
int foo( float *f, int *i ) { 
  *i = 1;               
  *f = 0.f;            
  return *i;
}


int main(int argc, char** argv) {
  int x = 10;
  int *ip = &x;

  std::cout << *ip << "\n";
  *ip = 12;
  std::cout << x << "\n";

  x = 0;
  x = foo(reinterpret_cast<float*>(&x), &x);
  std::cout << x << "\n";   // Expect 0?

  return 0;
}
