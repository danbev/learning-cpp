//$ clang++ -o hack hack.cc
#include <iostream>

#define private friend class Hack; private

class Foo {
 public:
  Foo(int v) : test_(v) {}
 private:
    void bar();
    int test_;
};

#undef private

void Foo::bar() { std::cout << "hello: " << test_ << std::endl; }

class Hack {
 public:
  static void bar(Foo& f) {
    f.bar();
  }
};

int main(int argc, char** argv) {
    Foo f(42);
    Hack::bar(f);
    return 0;
}
