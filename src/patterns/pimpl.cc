#include <iostream>
#include <string>
#include <memory>
#include "pimpl.h"

class Pimpl::Impl {
 public:
   Impl(const std::string& message) : message_(message) {};

   std::string message() const {
     return message_;
   }
 private:
   std::string message_;
};

Pimpl::Pimpl(const std::string& message) : 
  impl(std::make_unique<Pimpl::Impl>(message)) {
}

std::string Pimpl::message() const {
  return impl->message();
}

Pimpl::~Pimpl() {
}
