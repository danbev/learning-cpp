#include "simple_factory.h"
#include <iostream>
#include <gtest/gtest.h>

using namespace crypto;

TEST(Factory, simple) {
  Crypto* c = Factory::create("openssl_1_0_2e");
  EXPECT_EQ(false, c->encrypt(20));
  delete c;
}
