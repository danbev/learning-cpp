#include <memory>
#include <iostream>

class Something {
 public:
   Something() {
     std::cout << "Something constructed\n";
   }
   ~Something() {
     std::cout << "Something destructed\n";
   }

   void something() {
     std::cout << "doing something\n";
   }
};

int main(int argc, char** argv) {
  std::shared_ptr<Something> s1;
  std::shared_ptr<Something> s2;
  std::cout << "Before creation\n";
  {
    std::cout << "In creation scope/block\n";
    s1 = std::shared_ptr<Something>(new Something());
    std::cout << "use_count: " << s1.use_count() << '\n';
    s2 = std::shared_ptr<Something>(s1);
    std::cout << "use_count: " << s1.use_count() << '\n';
    std::cout << "Exit scope/block but use count is not 0 so not destructor called.\n";
  }

  s2->something();
}
