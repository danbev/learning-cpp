#ifndef OPENSSL__H__
#define OPENSSL__H__

namespace crypto {

class OpenSSL : public Crypto {
 public: 
  bool encrypt(int x);
};

}  //  crypto

#endif  //  OPENSSL__H__
