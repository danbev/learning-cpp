#include "simple_factory.h"
#include "crypto.h"
#include "openssl.h"
#include <string>

namespace crypto {

Crypto* Factory::create(const std::string& type) {
  if (type == "openssl_1_0_2e") {
    return new OpenSSL();
  }
  return nullptr;
}

}  //  crypto
