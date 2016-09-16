#include <gtest/gtest.h>
#include <iostream>

class In {
  public:
    int age = 10;
};

class Out {
  public:
    int two;
    In* in;
};

TEST(Util, cast) {
  // background on pointer to members:
  // we are creating a int pointer named twoprt which contain the address
  // of the two member of a Out instance. So just as we can use out.two, we ca
  // use out.*twoptr
  int Out::*twoptr = &Out::two;
  Out out1;
  out1.two = 33;
  EXPECT_EQ(33, out1.two);
  EXPECT_EQ(33, out1.*twoptr);
  out1.*twoptr = 44;
  EXPECT_EQ(44, out1.two);
  EXPECT_EQ(44, out1.*twoptr);
  EXPECT_EQ(&out1.two, &(out1.*twoptr));
}
