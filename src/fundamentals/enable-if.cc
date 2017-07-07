#include <iostream>

template <bool, typename T = void>
struct _enable_if {
};

template <typename T>
struct _enable_if<true, T> {
  typedef T type;
};

int doit(...) {
  std::cout << "doit(...)" << '\n';
  return 0;
}

template <typename T>
//typename std::enable_if<std::is_integral<T>::value, int>::type doit(T value) {
typename _enable_if<std::is_integral<T>::value, int>::type doit(T value) {
  std::cout << "template doit(...)" << '\n';
  return 1;
}

template <typename T>
typename T::value_type doit(T value) {
  return value;
};

int main(int argc, char* argv[]) {
  int first = doit("bajja");
  int second = doit(10);
  int third = doit(true);
  return 0;
}
