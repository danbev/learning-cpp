#include <gtest/gtest.h>
#include <iostream>

using namespace std;

class A {

  protected:
    int anr_ = 10;

  private: 
    int hidden = -10;

};

class B {
  protected:
    int bnr_ = 20;

  private:
    int hidden = -20;

};

class C : A, B {

  public: 
    int anumber() {
      return anr_;
    }

};

TEST(Protected, protected) {
  C c;
  EXPECT_EQ(10, c.anumber());
}

