#include <string>
#include <iostream>

using std::cout;
using std::string;

class Base {
  private:
    string name_;
  public:

    Base(string name) : name_(name) {
      cout << "Base constructor called [" << name_ << "]" <<  '\n';
    }

    Base(Base const& rhs) : name_(rhs.name_) {
      cout << "Base copy construction called [" << name_ << "]"  << '\n';
    }

    // Can avoid memory allocation as we know that the rhs is a
    // temporary object
    Base(Base&& rhs) : name_(rhs.name_) {
      cout << "Base move construction called [" << name_ << "]"  << '\n';
      rhs.name_ = name_;
    }

    ~Base() {
      cout << "Base destructor called [" << name_ << "]"  << '\n';
    }

    // what are we passing by value instead of by reference?
    //
    Base& operator=(const Base rhs) {
      cout << "Base assignement operator called" << '\n';
      name_ = rhs.name_;
      return *this;
    }

    string name() const {
      return name_;
    }
};

void int_ref(int&& ref) {
  cout << ref << '\n';
}

int main(int argc, char** argv) {
  Base a{"Fletch"};
  Base b = std::move(a);

  int&& t = 20;
  cout << "t = " << t << '\n';
  cout << "&t = " << &t << '\n';
  int_ref(std::move(t));

  return 0;
}
