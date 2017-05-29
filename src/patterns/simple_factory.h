#ifndef FACTORY__H__
#define FACTORY__H__

#include "crypto.h"
#include <string>

namespace crypto {

class Factory {
 public: 
  static Crypto* create(const std::string& type);
};

}  //  crypto

#endif  //  FACTORY__H__
