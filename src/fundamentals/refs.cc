#include <iostream>

class Obj {
};

int main(int argc, char** argv) {

  int a = 10;
  int b = 20;
  const int c = 30;

  int* x = &a; // x is a pointer to int
  int& y = a;  // y is a reference to int
  int* const t = &a;

  std::cout << "ref x = " << *x << '\n';
  std::cout << "ref y = " << y << '\n';
  std::cout << "t = " << *t << '\n';
  std::cout << "&x = " << &x << " " << x << '\n';
  std::cout << "&y = " << &y << " " << y << '\n';
  std::cout << "&t = " << &t << " " << t << '\n';

  // this is not reassigning, it is setting the value referenced, which 
  // is x to the value b. y will always point to the address of x.
  y = b;
  //t = &c; cannot point to anything else.
  std::cout << "ref x = " << *x << '\n';
  std::cout << "ref y = " << y << '\n';
  std::cout << "t = " << *t << '\n';
  std::cout << "&y = " << &y << '\n';
  std::cout << "&x = " << &y << '\n';

  Obj* p = new Obj();
  Obj& o = *p;
  std::cout << "p = " << &p << '\n';
  std::cout << "o = " << &o << '\n';
  /*
  (lldb) expr p
  (Obj *) $6 = 0x0000000100300060
  (lldb) expr &o
  (Obj *) $8 = 0x0000000100300060
  */
  // A reference is a value on the stack, the address of the reference is the same
  // as the variable it was bound to. So if it was initialized to point to an int variable
  // the address of that variable will be what the reference contains. When using a reference
  // an implicit indirection operator will be used.
  const Obj* cp = p; 
  std::cout << "cp = " << &cp << '\n';

  delete p;

  return 0;
}
