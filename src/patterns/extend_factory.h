#ifndef EXTEND_FACTORY__H__
#define EXTEND_FACTORY__H__

#include "crypto.h"
#include <string>
#include <map>

namespace crypto {

class Factory {
 public: 
  typedef Crypto* (*CreateCallback)();
  static void RegisterCrypto(const std::string& type, CreateCallback cb);
  static void UnregisterCrypto(const std::string& type);
  static Crypto* Create(const std::string& type);
 private:
  typedef std::map<std::string, CreateCallback> CallbackMap;
  static CallbackMap crypto_libs;
};

}  //  crypto

#endif  //  EXTEND_FACTORY__H__
