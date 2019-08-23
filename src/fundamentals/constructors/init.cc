#include <string>
#include <iostream>

using std::cout;
using std::string;

class Base {
  private:
    string name_;
    string other_;
  public:
    Base(string name) : name_(name) {
      if (name_.length() == 1) {
        other_ = "other";
      }
      cout << "Base constructor called " << name << ", " << other_ << '\n';
    }

    string name() const {
      return name_;
    }

};

int main(int argc, char** argv) {
  Base b ("Fletch");
  cout << b.name() << '\n';

}

