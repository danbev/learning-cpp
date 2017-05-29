#ifndef CRYPTO__H__
#define CRYPTO__H__

namespace crypto {

class Crypto {
 public:
   virtual ~Crypto() {}
   virtual bool encrypt(int x) = 0;
};

}  //  crypto

#endif  //  CRYPTO__H__
