#include <type_traits>
#include <iostream>

template <typename T>
void doit(const T& v) {
  if (std::is_pointer<T>::value) {
    std::cout << "is a pointer" << '\n';
  } else {
    std::cout << "is not a  pointer" << '\n';
  }
}

int main(int argc, char* argv[]) {
  std::string s{"bajja"};
  doit(s);
  //auto s2 = std::unique_ptr<std::string>{new std::string(s)};
  //doit(s2.get());
  return 0;
}
