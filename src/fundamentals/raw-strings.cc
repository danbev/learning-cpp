#include <iostream>
#include <string>
 
using namespace std;

int main(int argc, char** argv) {
  string str = "First line.\nSecond line.\nEnd of message.\n";
  string raw_str = R"(First line.\nSecond line.\nEnd of message.\n)";
  cout << str << '\n';
  cout<< raw_str << '\n';
  return(0);
}
