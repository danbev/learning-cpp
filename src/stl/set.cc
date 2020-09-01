#include <set>
#include <iostream>
#include <iterator>

int main(int argc, char** argv) {
  std::set<int> s;
  s.insert(1);
  s.insert(2);
  s.insert(3);

  std::cout << "Size of s: " << s.size() << '\n';
  std::set<int>::iterator iter = s.begin();
  for (; iter != s.end(); iter++) {
    std::cout << *iter << '\n';
  }

  return 0;
}
