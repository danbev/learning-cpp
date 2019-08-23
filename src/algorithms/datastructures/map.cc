#include <map>
#include <iostream>
#include <string>

int main(int argc, char** argv) {
  std::map<std::string, std::string> map{};
  std::cout << "Map:" << '\n';
  map["one"] = "first";
  map["two"] =  "second";

  std::map<std::string, std::string>* map2 = &map;
  (*map2)["three"] = "third";
}
