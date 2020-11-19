#include <string>
#include <iostream>
#include <memory>

using std::string;

class Mutex {
 public: 
   Mutex() {
     std::cout << "Mutex constructor\n";
   }
   ~Mutex() {
     std::cout << "Mutex destructor\n";
   }
};

class Some {
  public:

    Some() {
      std::cout << "Some no-args constructor called: " << "name_: " << name_ << ", mutex_: " << mutex_.get() << '\n';
    }

    ~Some() {
      std::cout << "Some descructor called " << "name_: " << name_ << ", mutex_: " << mutex_.get() << '\n';
    }

    explicit Some(string name) : name_(name) {
      mutex_ = std::make_shared<Mutex>();
      std::cout << "Some explicit constructor called: " << "name_: " << name << ", mutex_: " << mutex_.get() << '\n';
    }

    Some(Some const& other) : name_(other.name_) {
      std::cout << "Some copy constructor called " << "name_: " << name_ << ", mutex_: " << mutex_.get() << '\n';
      *this = other;
    }

    Some& operator=(const Some& that) {
      std::cout << "Some operator=\n";
      name_ = that.name_;
      mutex_ = that.mutex_;

      return *this;
    }

    Some& operator=(Some&& that) {
      std::cout << "Some move operator=\n";
      mutex_ = std::move(that.mutex_);
      return *this;
    }

    string name() const {
      return name_;
    }

  private:
    string name_;
    std::shared_ptr<Mutex> mutex_;
};

int main(int argc, char** argv)  {
  Some s1("s1");
  Some s2 = s1;

  return 0;
}

