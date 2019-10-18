#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

int main(int argc, char** argv) {
  for (int i = 1; i <= 5; ++i) {
    cout << i << " ";
    this_thread::sleep_for(chrono::seconds(1));
  }
  cout << endl;
  return 0;
}
