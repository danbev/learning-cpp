#include <string>
#include <iostream>

using std::cout;
using std::endl;
using std::string;

/**
 * These classes are intendend to show an issue where we have 
 * a base class which has a non virtual destructor. If a pointer
 * to such a Base class is uses, but points to an instance of a 
 * subclass (Derivied in this case) only the Base class's destructor
 * will be called. The Derived class's destructor will never be called
 * and this could lead to undefined behaviour. 
 */
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
    // non virtual base class destructor
    ~Base() {
      cout << "Base descructor called " << endl;
      destroyed_++;
    }

    string name() const {
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
  private:
    static int instances_;
    static int destroyed_;
  public: 
    Derived(string name) : Base(name) {
      cout << "Derived constructor called" << endl;
      instances_++;
    }
    ~Derived() {
      cout << "Derived descructor called" << endl;
      destroyed_++;
    }
    static int instances() {
      return instances_;
    }

    static int destroyed() {
      return destroyed_;
    }
};
int Derived::instances_ = 0;
int Derived::destroyed_ = 0;

