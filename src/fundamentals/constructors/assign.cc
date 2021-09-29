#include <string>
#include <iostream>

using std::cout;
using std::endl;
using std::string;

class Base {
  protected:
    string name_;
  public:
    Base(string name) : name_(name) {
      cout << "Base constructor called for " << name << '\n';
    }
    ~Base() {
      cout << "Base destructor called for " << name_ << '\n';
    }
    Base(Base const& other) : name_(other.name_) {
      cout << "copy constructor called for " << this->name_ << '\n';
    }

    string name() const {
      return name_;
    }
};

class Derived : public Base {
  public: 
    Derived(string name) : Base(name) {
      cout << "Derived destructor called for " << name << '\n';
    }
    ~Derived() {
      cout << "Derived destructor called for " << name() << '\n';
    }
    Derived& operator= (const Derived& other) {
      cout << "Derived assignment operator: other.name: " << other.name_
        << " this.name: " << this->name_ << '\n';
      name_ = other.name_;
      return *this;
    }
};

int main(int argc, char** argv) {
  Derived d1{"d1"};
  Derived d2{"d2"};
  // Note that if d2 does not exist then the copy constructor will be used.
  d2 = d1;
  cout << d2.name() << '\n';

  return 0;
}

