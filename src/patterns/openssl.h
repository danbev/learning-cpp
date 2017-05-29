#ifndef OPENSSL__H__
#define OPENSSL__H__

#include <crypto.h>

namespace crypto {

class OpenSSL : public Crypto {
 public: 
  OpenSSL();
  ~OpenSSL();
  bool encrypt(int x);
  static Crypto* Create(); 
};

}  //  crypto

#endif  //  OPENSSL__H__
