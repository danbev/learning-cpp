#include <iostream> 
#include <string> 

unsigned long long operator"" _k(unsigned long long k) {
  return k * 1024;
}

std::string operator"" _something(const char* str, size_t n) {
  std::string ret = std::string(str);
  return ret + "_suffix";
}


int main(int argc, char** argv) {
  long long value = 256_k;
  std::cout << "value of 256_k: " << value << '\n';
  std::string s = "bajja"_something;
  std::cout << "value of s: " << s << '\n';
  return 0;
}
