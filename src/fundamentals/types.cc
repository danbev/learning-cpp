#include <cstdio>
#include <cstdint>
#include <iostream>

int main(int argc, char** argv) {
  printf("types...\n");
  double d = 1e-9;
  if (d == 0.000000001) {
    printf("id is equal to 0.000000001...\n");
  }
  printf("d=%lf\n", d);
  uint64_t d2 = 000000001;
  printf("d2=%lf\n", d2);

  std::cout.precision(10);
  std::cout << d << '\n';
  std::cout << d2 << '\n';

  return 0;
}
