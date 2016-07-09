#include <string>
#include <iostream>

using std::cout;
using std::endl;
using std::string;

/*
This example demonstrates umbiguous name lookup.

In file included from ./classes/ambig_test.cc:5:
../src/classes/ambig.cc:40:7: error: member 'handle_' found in multiple base classes of different types
      handle_ = 22;
      ^
../src/classes/ambig.cc:11:9: note: member found by ambiguous name lookup
    int handle_ = 1;
        ^
../src/classes/ambig.cc:33:7: note: member found by ambiguous name lookup
    T handle_;
      ^
1 error generated.
 */
class Base {
  private:
    string name_;
  protected:
    int handle_;
  public:
    Base(string name) : name_(name) {
      cout << "Base constructor called" << endl;
      handle_ = 1;
    }
    ~Base() {
      cout << "Base descructor called" << endl;
    }

    string name() const {
      return name_;
    }

    int handle() const {
      return handle_;
    }

};

template <typename T>
class Other {
  protected:
    T handle_;
};

class Derived : public Base, Other<int> {
  private:
    char handle_;
  public: 
    Derived(string name) : Base(name) {
      cout << "Derived constructor called" << endl;
      // will cause a compile time error as handle_ 
      handle_ = 'b'; 
    }
    ~Derived() {
      cout << "Derived descructor called" << endl;
    }
    Derived(Derived const& other) = delete;

    char handle() const {
      //return Other::handle_;
      return this->handle_;
    }

    int handleFromBase() const {
      return Base::handle_;
    }

};

