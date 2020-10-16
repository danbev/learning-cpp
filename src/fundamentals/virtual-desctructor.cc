#include <iostream>
#include <memory>

// $ g++ -g -fsanitize=address -o virtual-desctructor virtual-desctructor.cc
class Base { 
  public: 
    Base() {
      std::cout << "Constructing Base " << '\n'; 
    }
    ~Base() { std::cout << "Destructing Base " << '\n'; }      
    // Without a virtual destructor asan will produce an error
    //virtual ~Base() { std::cout << "Destructing Base " << '\n'; }      
}; 
  
class Derived: public Base { 
  public: 
    Derived() { std::cout << "Constructing Derived " << '\n'; } 
    ~Derived() { std::cout << "Destructing Derived " << '\n'; } 
  private:
    int x;
}; 
  
int main(void) 
{ 
  Derived *d = new Derived();   
  Base *b = d; 
  // we are deleting a Derived object through Base pointer. If the Base class's
  // destructor is not virtual the Derived class's destructor will not be run.
  delete b; 

  std::unique_ptr<Base> ptr1 = std::make_unique<Derived>();

  return 0; 
} 
