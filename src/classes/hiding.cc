#include <string>
#include <iostream>

using std::cout;
using std::endl;
using std::string;

class Base {
  private:
    string name_;
    int handle_ = 1;
  public:
    Base(string name) : name_(name) {
      cout << "Base constructor called" << endl;
    }
    ~Base() {
      cout << "Base descructor called" << endl;
    }
    Base(Base const& other) : name_(other.name_) {
      cout << "copy construction\n" << endl;
    }

    string name() const {
      return name_;
    }

    int handle() const {
      return handle_;
    }

};

class Derived : public Base {
  private:
    char handle_ = 'd';
  public: 
    Derived(string name) : Base(name) {
      cout << "Derived constructor called" << endl;
    }
    ~Derived() {
      cout << "Derived descructor called" << endl;
    }
    Derived(Derived const& other) = delete;

    char handle() const {
      return handle_;
    }

};

