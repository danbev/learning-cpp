#include <iostream>

using namespace std;

class QuickFind {
  private:
    int * entries;
    int n;

  public:
    QuickFind(int n) {
      this->n = n;
      entries  = new int[n];
      for (int i = 0; i < n; i++) {
        entries[i] = i;
      }
      cout << "Created new array with " << n << " elements" << endl;
    }
    void connect(int p, int q) {
      cout << "Connecting " << p << " and " << q << endl;
      int srcGroup = entries[p];
      int dstGroup = entries[q];
      entries[q] = srcGroup;
      for (int i = 0; i < n; i++) {
        if (entries[i] == dstGroup) {
          entries[i] = srcGroup;
        }
      }
    }
    bool connected(int p, int q) {
      return entries[q] == p;
    }
    void print() {
      cout << "[";
      for (int i = 0; i < n; i++) {
        cout << i << "=" << entries[i] << ", ";
      }
      cout << "]" << endl;
    }
    ~QuickFind() {
      delete [] entries;
      cout << "Deleted array " << endl;
    }
    int size() {
      return n;
    }
};

int main() {
  cout.setf(ios::boolalpha);
  QuickFind uf (10);
  uf.print();
  uf.connect(0, 1);
  uf.print();
  cout << "Are 0,1 connected: " << uf.connected(0, 1) << endl;
  uf.connect(8, 9);
  uf.print();
  // should join the two groups
  uf.connect(0,8);
  uf.print();
  return 0;
}
