#include <iostream>

//$ clang++ -Wimplicit-fallthrough -std=c++11 -o fallthrough fallthrough.cc 
int main(int argc, char** argv) {
  int nr = 2;
  int result = 0;
  switch(nr) {
    case 1:
      result = 1;
      break;
    case 2:
      std::cout << "case 2, fallthrough... \n";
      [[clang::fallthrough]];
    case 4:
      result = -1;
      break;
  }

  std::cout << "result = " << result << '\n';
  return 0;
}
