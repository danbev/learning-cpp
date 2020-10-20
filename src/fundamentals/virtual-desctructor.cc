#include <iostream>
#include <memory>

/*
extern "C" const char* __asan_default_options() {
  return "new_delete_type_mismatch=0";
}
*/

// $ g++ -g -fsanitize=address -o virtual-desctructor virtual-desctructor.cc
class Base { 
  public: 
    Base() {
      std::cout << "Constructing Base " << this << '\n'; 
    }
    ~Base() { std::cout << "~Base " << this << '\n'; }      
    // Without a virtual destructor asan will produce an error
    //virtual ~Base() { std::cout << "~Base " << this <<  '\n'; }      
    //virtual ~Base() { std::cout << "~Base " << this <<  '\n'; }      
}; 
  
class Derived: public Base { 
  public: 
    Derived() { std::cout << "Constructing Derived " << this << '\n'; } 
    ~Derived() { std::cout << "~Derived (Important that this gets called) " << this << '\n'; } 
  private:
    int x;
    bool b : 1;
}; 

class Derived2: public Base {
  public: 
    Derived2() { std::cout << "Constructing Derived2 " << this << '\n'; } 
    ~Derived2() { 
      std::cout << "~Derived2 " << this << '\n';
      Derived* d= reinterpret_cast<Derived*>(this);
      d->~Derived();
    } 
    char s[10000];
}; 

int main(void) 
{ 
  Derived* d = new Derived();   
  Derived2* d2 = reinterpret_cast<Derived2*>(d);
  delete d2;

  /*
  Derived2* d3 = new Derived2();
  delete d3;
  */
  // Deallocation size different from allocation size


  return 0; 
} 
