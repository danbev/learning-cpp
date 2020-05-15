#include <functional>
#include <iostream>

using Callback = std::function<int(int x)>;

void doit(Callback cb) {
  if (cb != nullptr) {
    int ret = cb(10);
    std::cout << "ret:" << ret << '\n';
  }
}

int main(int argc, char** argv) {
  Callback cb = [](int x) { return 10;};
  doit(cb);
  doit(Callback{});
  return 0;
}
