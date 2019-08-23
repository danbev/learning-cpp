#include <functional>
#include <iostream>

template <typename F, typename... T> 
struct Defer {
  Defer(F&& f, T&&... t)
      : f(std::bind(std::forward<F>(f), std::forward<T>(t)...)) {}

  Defer(Defer&& o) noexcept : f(std::move(o.f)) {}
  ~Defer() { f(); }

  using ResultType = typename std::result_of<typename std::decay<F>::type(
      typename std::decay<T>::type...)>::type;
  std::function<ResultType()> f;
};

template <typename F, typename... T> Defer<F, T...> defer(F&& f, T&&... t) {
  return Defer<F, T...>(std::forward<F>(f), std::forward<T>(t)...);
}

int after(int input) {
  std::cout << "after...:" << input << '\n';
  return input++;
}

typedef std::decay<int>::type A;
typedef std::decay<int[]>::type Array;

void print_sizeof(int (&array)[10]) {
  std::cout << "sizeof array: " << sizeof(array) << '\n';
}

void print_sizeof2(Array array) {
  std::cout << "sizeof array: " << sizeof(array) << '\n';
}

void print(const int x) {
  std::cout << x << '\n';
}
int main(int argc, char** argv) {

  std::cout << "defer..." << '\n';
  {
    std::cout << "entered scope..." << '\n';
    auto ret = defer(after, 18);
    std::cout << "work in scope..." << '\n';
  }

  A a = 20;
  Array array[3];
  int array2[10];
  std::cout << "sizeof array: " << sizeof(array2) << '\n';
  print_sizeof(array2);
  print_sizeof2(array2);

  int i = 18;
  const auto func = std::bind(&print, i);
  func();
  i++;
  func();
  const auto func2 = std::bind(&print, std::ref(i));
  func2();
  i++;
  func2();


}
