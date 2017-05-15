#include <gtest/gtest.h>
#include <iostream>
#include <string>
#include "template-header.h"

using namespace std;

TEST(TemplateClass, linking) {
  TemplateClass<int> t{10};
  t.get();
  t.print();
  //t.usage();
  t.staticPrint(t.get());
  //EXPECT_EQ(3, Base::destroyed()) << "Destructor should have been called three times";
}

