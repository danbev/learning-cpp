#include <gtest/gtest.h>
#include <iostream>
#include "triangular_array.cpp"

int cities[4][4] {
 //               Chicago   NY        LA        San Fran 
 /* Chicago  */   {0,       790,      1745,     1852}, 
 /* New York */   {790,       0,      2776,     2564}, 
 /* LA       */   {1745,    2776,        0,      381}, 
 /* San Fran */   {1852,    2564,       381,       0} 
};
// All 0 are redudant. So 4 entries could be removed.
/*
               Chicago   NY        LA        San Fran 
  Chicago      {-,       790,      1745,     1852}, 
  New York     {790,       -,      2776,     2564}, 
  LA           {1745,    2776,        -,      381}, 
  San Fran     {1852,    2564,       381,       -} 
*/
// All have double refs to each other, 
// LA-NY and NY-LA, so more entries can be removed:
/*
               Chicago   NY        LA        San Fran 
  Chicago      {-,        --,         -,        -}, 
  New York     {790,       -,         -,        -}, 
  LA           {1745,    2776,        -,        -}, 
  San Fran     {1852,    2564,       381,       -} 
So we can see that the whole first line can be removed. Also note how we have removed
all entries with a line through the diagonal.
So we have removed:
4 + 3 + 2 + 1 = 10 entries. The previous size was 16 so we need to have an array of 6.
This can be calculated using N * (N-1)/2, 4 * (4-1)/2 = 12/2=6.
This is how the size of the one dimentional array is calculated.
*/

//int tri[6] = {790, 1745, 2776, 1852, 2564, 381};

TEST(tri, initialize) {
  TriArr tri (4);
  EXPECT_EQ(6, tri.length());
}

TEST(tri, rowZero) {
  TriArr tri (4);
  /* Chicago  {0,       790,      1745,     1852}, */
  EXPECT_EQ(1 * (1-1)/2, tri.index(0, 1));
  EXPECT_EQ(2 * (2-1)/2, tri.index(0, 2));
}

TEST(tri, index) {
  TriArr tri (4);
  EXPECT_EQ(1, tri.index(0, 2));
  EXPECT_EQ(3, tri.index(0, 3));
  EXPECT_EQ(2, tri.index(1, 2));
}

