#include <iostream>

using namespace std;

class QuickFind {
  private:
    int * entries;
    int n;
    int comps;

  public:
    QuickFind(int n) {
      this->n = n;
      this->comps = n;
      entries  = new int[n];
      for (int i = 0; i < n; i++) {
        entries[i] = i;
      }
      cout << "Created new array with " << n << " elements" << endl;
    }

    void connect(int p, int q) {
      cout << "Connecting " << p << " and " << q << endl;
      int srcGroup = entries[p]; // first access of array
      int dstGroup = entries[q]; // second access of array
      for (int i = 0; i < n; i++) { // N accesses
        if (entries[i] == srcGroup) {
          entries[i] = dstGroup;
        }
      }
      comps--;
    }

    bool connected(int p, int q) {
      return entries[p] == entries[q];
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

    int components() {
      return comps;
    }
};

