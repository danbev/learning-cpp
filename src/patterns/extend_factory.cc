#include "extend_factory.h"
#include "crypto.h"
#include <string>

namespace crypto {

Factory::CallbackMap Factory::crypto_libs;

void Factory::RegisterCrypto(const std::string& type, CreateCallback cb) {
  crypto_libs[type] = cb;
}

void Factory::UnregisterCrypto(const std::string& type) {
  crypto_libs.erase(type);
}

Crypto* Factory::Create(const std::string& type) {
  CallbackMap::iterator it = crypto_libs.find(type);
  if (it != crypto_libs.end()) {
    return (it->second)();
  }
  return nullptr;
}

}  //  crypto
