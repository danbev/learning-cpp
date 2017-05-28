#ifndef PIMPL__H__
#define PIMPL__H__

#include <string>

class Pimpl {
 public:
  explicit Pimpl(const std::string& message);
  std::string message() const;
  ~Pimpl();
 private:
  // Copy constructor should disabled
  Pimpl(const Pimpl&);
  // Assignment operator should disabled
  const Pimpl operator=(const Pimpl&);
  class Impl;
  Impl* impl;
};

#endif
