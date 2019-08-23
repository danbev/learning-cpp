#include <iostream>

class Obj {

};

int main(int argc, char** argv) {
  Obj o;
  Obj& o_l_ref = o;
  Obj&& o_r_ref = o;


  return 0;
}
