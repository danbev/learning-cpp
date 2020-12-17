#include <iostream>
#include <sstream>

class StdErrScope {
 public:
  StdErrScope(std::streambuf* buf) : old_(std::cerr.rdbuf(buf)) {}
  ~StdErrScope() {
    std::cerr.rdbuf(old_);
  }

 private:
  std::streambuf* old_;
};

int main(int argc, char** argv) {
  std::cerr << "before...\n";
  std::stringstream buffer;
  std::streambuf* old = std::cerr.rdbuf(buffer.rdbuf());
  std::cerr << "in...\n";
  std::cerr.rdbuf(old);
  std::cerr << "after...\n";

  std::cerr << "before scope...\n";
  {
    StdErrScope scope(buffer.rdbuf());
    std::cerr << "in...\n";
  }
  std::cerr << "after scope...\n";
}
