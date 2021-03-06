#include <iostream>
#include <list>
#include <algorithm>

struct Foo {
  Foo() { std::cout << "Foo ctor\n"; }
  ~Foo() { 
    std::cout << "~Foo\n"; 
    nr = 0;
  }
  void doit() {
    std::cout << "doing it..." <<  nr << '\n';
  }
  int nr = 10;
};


Foo* something() {
  std::unique_ptr<Foo> f2 {new Foo()};
  Foo* f2_ptr = f2.get();
  //f2.release();
  std::cout << f2_ptr << '\n';
  return f2_ptr;
}

int main(int argc, char** argv) {
  /*
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
    std::unique_ptr<Foo> f{new Foo()};
    list.push_back(f.get());
    x--;
  }
  for (std::list<Foo*>::iterator it = list.begin(); it != list.end(); ++it){
    Foo* tmp = *it;
    tmp->doit();
  }

  std::cout << "give up..." << '\n';
  std::unique_ptr<Foo> give_up{new Foo()};
  Foo* fp = give_up.release();
  */

  Foo* f = something();
  f->doit();
  
  return 0;
}
