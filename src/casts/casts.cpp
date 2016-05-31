#include <memory>
#include <string>

class Base {
    public:
        virtual std::string name() {
            return "base";
        }
};

class Derived : public Base {
    public: 
        std::string name() {
            return "derived";
        }
};

/**
 * Just an example of a normal case from a derived class to a base class.
 */
Base* cast() {
    Derived* d = new Derived();
    return (Base*)d;
}

