#include <string>
#include <list>

class Args {

  public:
    Args(const std::initializer_list<const char*> &l) {
      size_ = l.size();
      auto it = l.begin();
      name_ = *it;
      ++it;
      for (; it != l.end(); ++it) {
        ls_.push_back(*it);
      }
    }

    std::list<const char*>& ls() {
      return ls_;
    }

    const char* name() {
      return name_;
    }

    const int size() {
      return size_;
    }

  private:
    const char* name_;
    int size_;
    std::list<const char*> ls_;

};


