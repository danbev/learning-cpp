#include <iostream>

// $ clang++ -Wmost -std=c++11 -o virtuald virtual-desctructor.cc
class Base { 
  public: 
    Base() { std::cout << "Constructing Base " << '\n'; } 
    virtual void doit() { std::cout << "Base doit..." << '\n'; }
    virtual ~Base() { std::cout << "Destructing Base " << '\n'; }      
}; 
  
class Derived: public Base { 
  public: 
    Derived() { std::cout << "Constructing Derived " << '\n'; } 
    ~Derived() { std::cout << "Destructing Derived " << '\n'; } 
    void doit() { std::cout << "Derived doit..." << '\n'; }
}; 
  
int main(void) 
{ 
  Derived *d = new Derived();   
  Base *b = d; 
  delete b; 
  return 0; 
} 
