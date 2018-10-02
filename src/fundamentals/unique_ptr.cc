#include <iostream>
#include <list>
#include <algorithm>

struct Foo {
  Foo() { std::cout << "Foo\n"; }
  ~Foo() { std::cout << "~Foo\n"; }
  void doit() {
    std::cout << "doing it..." << '\n';
  }
};


int main(int argc, char** argv) {
  std::cout << "Creating new Foo...\n";
  Foo* f;
  {
    std::unique_ptr<Foo> up(new Foo());
    f = up.release();
  }
  std::cout << f << '\n';
  std::unique_ptr<Foo> up2(f);
  up2->doit();
  up2.release();;

  std::list<Foo*> list;
  int x = 5;
  while (x >= 0) {
    std::unique_ptr<Foo> f(new Foo());
    list.push_back(f.get());
    x--;
  }
  for (std::list<Foo*>::iterator it = list.begin(); it != list.end(); ++it){
    Foo* tmp = *it;
    tmp->doit();
  }
  return 0;
}
