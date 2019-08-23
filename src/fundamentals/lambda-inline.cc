#include <functional>
#include <iostream>
#include <type_traits>

// $ clang++ -O2 -std=c++11 -o lambda-inline lambda-inline.cc
// And compare with compiling without optimization:
// $ clang++ -std=c++11 -o lambda-inline lambda-inline.cc
// Notice that with optimization the lambda operator() will be inlined.
template<typename Func>
void run(Func f) {
  f();
}

int main(int argc, char** argv) {
  int x = 10;
  run([&x]() {
    x += 1;
  });
  int y = x;
  run([&y]() {
    y = y+1;
  });
  x = y;

  const char name[] = "Fletch";
  decltype(name) c = "Fletch";
  decltype(x) typex;
  std::cout << c << '\n';
  std::cout << typex << '\n';
  //std::is_array<std::remove_reference_t<decltype(name)>>::value;
  //std::cout << std::remove_reference<decltype("sss")> << '\n';
  std::cout << std::boolalpha << std::is_array< typename std::remove_reference<decltype("sss")>::type >::value << '\n';
  return x;
}
