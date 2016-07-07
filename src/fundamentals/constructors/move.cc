#include <string>
#include <iostream>

using std::cout;
using std::endl;
using std::string;

class Base {
  private:
    static int instances_;
    static int moveInstances_;
    static int copied_;
    static int destroyed_;
    string name_;
  public:

    Base(string name) : name_(name) {
      cout << "Base constructor called" << endl;
      instances_++;
    }

    Base(Base const& rhs) : name_(rhs.name_) {
      cout << "Base copy construction called" << endl;
      copied_++;
    }

    // Can avoid memory allocation as we know that the rhs is a
    // temporary object
    Base(Base&& rhs) : name_(rhs.name_) {
      cout << "Base move construction called" << endl;
      rhs.name_ = "";
      moveInstances_++;
    }

    ~Base() {
      cout << "Base descructor called" << endl;
      destroyed_++;
    }

    // what are we passing by value instead of by reference?
    //
    Base& operator=(const Base rhs) {
      cout << "Base assignement operator called" << endl;
      name_ = rhs.name_;
      return *this;
    }

    string name() const {
      return name_;
    }

    static int instances() {
      return instances_;
    }

    static int moveInstances() {
      return moveInstances_;
    }

    static int destroyed() {
      return destroyed_;
    }

    static int copied() {
      return copied_;
    }

};
int Base::instances_ = 0;
int Base::moveInstances_ = 0;
int Base::destroyed_ = 0;
int Base::copied_ = 0;
