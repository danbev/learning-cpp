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
    virtual ~Base() {
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

class Derived2 : public Derived {
  private:
    static int instances_;
  public: 
    Derived2(string name) : Derived(name) {
      cout << "Derived constructor called" << endl;
      instances_++;
    }
    ~Derived2() = default;

    static int instances() {
      return instances_;
    }
};
int Derived2::instances_ = 0;

