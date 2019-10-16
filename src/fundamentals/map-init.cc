#include <iostream>
#include <unordered_map>


std::unordered_map<int, std::string> something() {
  return {};
}

int main(int argc, char** argv) {
  std::unordered_map<int, std::string> map;
  std::cout << "is map empty:" <<  (map.empty() ? "true": "false") << '\n';
  map[1] = "first";
  std::cout << "is map empty:" <<  (map.empty() ? "true": "false") << '\n';

  map.insert(std::make_pair(2, "second"));

  for (std::unordered_map<int, std::string>::iterator it = map.begin(); it != map.end(); it++) {
    std::cout << it->first << ":" << it->second << '\n';
  }

  if (map.find(1) != map.end()) {
    std::cout << "has key 1" << '\n';
  }

  std::unordered_map<int, std::string> e = something();
  std::cout << "e is empty? " <<  (e.empty() ? "true": "false") << '\n';
}
