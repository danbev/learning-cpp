#include "crypto.h"
#include "iostream"

namespace crypto {

class OpenSSL : public Crypto {
  OpenSSL();
  ~OpenSSL();
  bool encrypt(int x);
};

OpenSSL::OpenSSL() {
  std::cout << "OpenSSL construction...\n";
}

OpenSSL::~OpenSSL() {
  std::cout << "OpenSSL destruction...\n";
}

bool OpenSSL::encrypt(int x) {
  std::cout << "OpenSSL encrypting...\n";
  return false;
}

}  //  crypto
