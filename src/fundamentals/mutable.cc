#include <iostream>
#include <string>

class Something {
 public:
   Something(std::string name) : name_(name) {}

   const std::string& name() const { 
     return name_;
     counter_++; // can be mutated even though function is const. 
   }

 private:
   mutable int counter_ = 0;
   std::string name_;

};

int main(int argc, char** argv) {
  const Something s("Fletch");
  std::cout << "s.name_: " << s.name() << '\n';

  return 0;
}

