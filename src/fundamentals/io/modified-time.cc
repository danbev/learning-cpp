#include <fstream>
#include <iostream>
#include <utime.h>

int main(int argc, char** argv) {
  std::cout << "Open file and update modified time (mtime)" << '\n';
  std::ofstream out;
  out.open("testing.txt", std::ofstream::out | std::ofstream::app);
  out.close();

  utime("testing.txt", 0);
  return 0;
}
