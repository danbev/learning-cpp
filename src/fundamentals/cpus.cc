#include <thread>
#include <iostream>

int main(int argc, char** argv) {
  const auto count = std::thread::hardware_concurrency();
  std::cout << "Nr of cpus: " << count << '\n';

  return 0;
}
