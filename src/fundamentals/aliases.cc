#include <iostream>
#include <vector>

template<class T> using ptr = T*;

int main(int argc, char** argv) {
  using Ints = std::vector<int>;
  using IntIterator = std::vector<int>::iterator;
  Ints ints {1, 2, 3};
  IntIterator iter = ints.begin();
  ptr<int> x;

  return 0;
}
