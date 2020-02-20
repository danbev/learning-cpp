#include "library.h"
#include <iostream>

int main(int argc, char** argv) {
  std::cout << "main..." << '\n';
  library::Something newer{};
  library::v1::Something older{};
  return 0;
}
