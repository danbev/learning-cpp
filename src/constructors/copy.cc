#include <string>
#include <iostream>

using std::cout;
using std::endl;
using std::string;

class Base {
  private:
    static int instances_;
    static int destroyed_;
    string name_;
  public:
    Base(string name) : name_(name) {
      cout << "Base constructor called" << endl;
      instances_++;
    }
    ~Base() {
      cout << "Base descructor called " << destroyed_ << endl;
      destroyed_++;
    }

    string name() {
      return name_;
    }

    static int instances() {
      return instances_;
    }

    static int destroyed() {
      return destroyed_;
    }
};
int Base::instances_ = 0;
int Base::destroyed_ = 0;

class Derived : public Base {
  public: 
    Derived(string name) : Base(name) {
      cout << "Derived constructor called" << endl;
    }
    ~Derived() {
      cout << "Derived descructor called" << endl;
    }
};

