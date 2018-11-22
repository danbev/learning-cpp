#ifndef PIMPL__H__
#define PIMPL__H__

#include <string>

class Pimpl {

 class Impl;

 public:
  explicit Pimpl(const std::string& message);
  // Copy constructor should disabled
  Pimpl(const Pimpl&) = delete;
  ~Pimpl();
  // Assignment operator should disabled
  const Pimpl operator=(const Pimpl&) = delete;
  std::string message() const;
 private:
  //Pimpl(const Pimpl&);

  std::unique_ptr<Impl> impl;
};

#endif
