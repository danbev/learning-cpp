#include <iostream>
#include <sstream>
#include <iomanip>

int main(int argc, char** argv) {
  bool yes = true;
  std::stringstream data (std::ios::out);
  data << "yes: " << std::boolalpha << yes << '\n';

  std::cout << data.str();

  std::cout <<  std::resetiosflags(std::ios_base::dec);
  std::cout << std::setiosflags(std::ios::hex | std::ios::showbase | std::ios::uppercase) << 10 << '\n';

  return 0;
}
