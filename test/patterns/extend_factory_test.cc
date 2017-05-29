#include "extend_factory.h"
#include "openssl.h"
#include <iostream>
#include <gtest/gtest.h>

using namespace crypto;

TEST(ExtendFactory, extend) {
  Factory::RegisterCrypto("openssl_1_0_2e", OpenSSL::Create);
  Crypto* c = Factory::Create("openssl_1_0_2e");
  EXPECT_EQ(false, c->encrypt(20));
  delete c;
}
