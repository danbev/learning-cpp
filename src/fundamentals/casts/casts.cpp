#include <memory>
#include <string>

class Base {
  private: 
    std::string _name;

    public:
      Base(std::string name = "base"): _name(name) {
      }

      virtual std::string name() {
        return _name;
      }

};

class Derived : public Base {
  public: 
    Derived(std::string name = "derived") : Base(name) {
    }

    std::string name() {
        return "derived";
    }

    std::string dname() {
      return "dname";
    }

};

/**
 * Just an example of a normal case from a derived class to a base class.
 */
Base* cast() {
    Derived* d = new Derived();
    return (Base*) d;
}

