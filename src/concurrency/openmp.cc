#include <iostream>
#include <omp.h>

int main(int argc, char** argv) {

  #pragma omp parallel num_threads(4)
  {
  #pragma omp critical
    std::cout << "First " << " OpenMP " << " example. Thread num: " <<
      omp_get_thread_num() << '\n';
  }

  return 0;
}
