#include <gtest/gtest.h>
#include <forward_list>
#include <iostream>

using namespace std;

TEST(ForwardList, list) {
  forward_list<int> list = {1, 2, 3};
  for (auto item : list) {
    cout << item << endl;
  }
  //EXPECT_EQ(10, b);
}
