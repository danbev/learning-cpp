#include <iostream>
#include <StringBad.h>
using std::cout;

void passByRef(StringBad &);
void passByValue(StringBad);

int main() {
  using std::endl;
  {
    cout << "Starting inner block..." << endl;
    StringBad first("Fletch");
    //passByRef(first);
    passByValue(first);
  }
  return 0;
}

void passByRef(StringBad &sb) {
  cout << "passByRef: " << sb << std::endl;
}

// passing by value will invoke the copy constructor. A copy constructor is used
// when passing arguments by value. This means that a new instance of our class
// will be created but that instance will not be created with either of our 
// A Copy Constructor creates a copy by doing a member by member copy. So the
// new instance would have:
// str = sb.str; // this is making both point to the same char[] in memory
// len = sb.len; 
// When the destructor run for the first instace the memory reclamin/delete 
// will succeed. But for the second instance that same delete will fail
// as that memory has already been reclaimed.
void passByValue(StringBad sb) {
  cout << "passByValue: " << sb << std::endl;
}
