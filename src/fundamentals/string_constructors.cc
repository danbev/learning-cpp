#include <iostream>
#include <string>

std::string make_cid_key(const uint8_t *cid, size_t cidlen) {
  std::cout << "cid:" << cid << ", cidlen:" << cidlen  << '\n';
  return std::string(cid, cid + cidlen);
}

// $ clang++ -std=c++17 -o string_c string_constructors.cc
int main(int argc, char** argv) {
  std::cout << "string repeated constructor example:" << '\n';
  std::string s(18, '?');
  std::cout << s << '\n';

  uint8_t cid = 'xxxxxxxxxxxxxxxxxxxxxxxxxxxx';
  uint8_t cidlen = 18;
  uint8_t* pcid = &cid;
  std::cout << "cid:" << pcid << '\n';
  // first argument is the count copies of ch (second argument)
  std::string r = make_cid_key(pcid, cidlen);
  std::cout << r << '\n';
}
