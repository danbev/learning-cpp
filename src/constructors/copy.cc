#include <string>
#include <iostream>

using std::cout;
using std::endl;
using std::string;

class Base {
  private:
    static int instances_;
    string name_;
  public:
    Base(string name) : name_(name) {
      cout << "Base constructor called" << endl;
      instances_++;
    }
    ~Base() {
      cout << "Base descructor called" << endl;
      instances_--;
    }

    string name() {
      return name_;
    }
    static int instances() {
      return instances_;
    }
};
int Base::instances_ = 0;

class Derived : public Base {
  public: 
    Derived(string name) : Base(name) {
      cout << "Derived constructor called" << endl;
    }
    ~Derived() {
      cout << "Derived descructor called" << endl;
    }
};

