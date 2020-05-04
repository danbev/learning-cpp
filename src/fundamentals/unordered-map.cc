#include <unordered_map>
#include <iostream>

int main(int argc, char** argv) {
  std::unordered_map<int, char> map{{1, 'a'}};

  // using explicit type intentionally instead of auto.
  std::unordered_map<int,char>::iterator iter = map.find(1);
  if (iter != map.end()) {
    std::cout << iter->first << ":" << iter->second << '\n';
  }
  return 0;
}
