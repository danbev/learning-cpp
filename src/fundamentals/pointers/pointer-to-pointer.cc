#include <iostream>

int main(int argc, char** argv) {
  int c = 18;
  int* b = &c;
  int** a = &b;

  std::cout << "c=" << c << '\n';
  std::cout << "b=" << b << '\n';
  std::cout << "a=" << a << '\n';

  std::cout << "a value=" << *a << '\n';
  std::cout << "b value=" << *b << '\n';

  char const* s = "bajja";
  char const** ss;
  ss = &s;

  std::cout << "size of char*:" << sizeof(char*) << '\n';

  std::cout << "argc:" << argc << '\n';
  std::cout << "argv:" << argv << '\n';
  char* progname = *argv;
  char* first_arg = *++argv;
  std::cout << "*argv:" << progname << '\n';
  std::cout << "*argv:" << first_arg << '\n';

  return 0;
}
