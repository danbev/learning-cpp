#ifndef PIMPL__H__
#define PIMPL__H__

#include <string>

class Pimpl {
 public:
  Pimpl(const std::string& message);
  std::string message() const;
  ~Pimpl();
 private:
  class Impl;
  Impl* impl;
};

#endif
