#include "object-linkage.h"
#include <iostream>

int main(int argc, char** argv) {
  std::cout << "-Wsubobject-linkage warning example\n";
  Something s;
  return 0;
}

