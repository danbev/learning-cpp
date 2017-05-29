#include "openssl.h"
#include "iostream"

namespace crypto {

OpenSSL::OpenSSL() {
  std::cout << "OpenSSL construction...\n";
}

OpenSSL::~OpenSSL() {
  std::cout << "OpenSSL destruction...\n";
}

Crypto* OpenSSL::Create() {
  std::cout << "OpenSSL Create...\n";
  return new OpenSSL();
}

bool OpenSSL::encrypt(int x) {
  std::cout << "OpenSSL encrypting...\n";
  return false;
}

}  //  crypto
