#include <gtest/gtest.h>
#include <iostream>
#include <typeinfo>

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

class ConstExample {

  public:
    ConstExample() : ptr_(0) { };
    ConstExample(const ConstExample& e) : ptr_(reinterpret_cast<int*>(*e)) { };

    int* operator*() const { return ptr_; }

    static ConstExample New (int* val) {
      return ConstExample(val);
    }

  private:
    int* ptr_ = nullptr;
    explicit ConstExample(int* that) : ptr_(that) {}
};

void something(ConstExample c) {
  std::cout << typeid(*c).name() << '\n';
  ///std::cout << std::type_name<decltype(i)>() << '\n';
  printf(" %s\n", __PRETTY_FUNCTION__);
  std::cout << "Address of c : " << &c << '\n';
  std::cout << "Value of c : " << **c << '\n';
  int* a = new int{10};
  ConstExample c2 = ConstExample::New(a);
  **c = **c2;
}

TEST(Pointers, constExample) {
  int* a = new int{10};
  ConstExample ce = ConstExample::New(a);
  EXPECT_EQ(10, *(*ce));
  int* b = *ce;
  EXPECT_EQ(10, *b);
  EXPECT_NE(&a, &b);
  EXPECT_EQ(a, b);
  *b = 100;
  EXPECT_EQ(100, *b);
  EXPECT_EQ(100, *a);
  std::cout << "Address of ce : " << &ce << '\n';
  std::cout << "Value of ce : " << **ce << '\n';
  something(ce);
  std::cout << "Value of ce : " << **ce << '\n';
  EXPECT_EQ(10, **ce);
}
