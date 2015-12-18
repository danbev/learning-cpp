// clang++ -std=c++11 -stdlib=libc++ membinit.cpp -o membinit
#include <iostream>

class MemberInit {
  private:
    char * name;
  public:
    MemberInit(char *n ) : name(n) {}
    char * getName() {
      return name;
    }
};

using namespace std;

int main(void) {
  char name[] = "testing";
  char * n = name;
  MemberInit t = MemberInit(name);
  cout << t.getName() << endl;
  return 0;
}
