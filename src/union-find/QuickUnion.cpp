#include <iostream>

using namespace std;

class QuickUnion {
  private:
    int * entries;
    int * sizes;
    int n;
    int sets;

  public:

    QuickUnion(int n) {
      this->n = n;
      this->sets = n;
      entries  = new int[n];
      sizes  = new int[n];
      for (int i = 0; i < n; i++) {
        entries[i] = i;
        sizes[i] = 1; 
      }
      cout << "Created new array with " << n << " elements" << endl;
    }

    int root(int p) {
      while(p != entries[p]) {
        p = entries[p];
      }
      return p;
    }

    void connect(int p, int q) {
      cout << "Union p=" << p << " and q=" << q << endl;
      int i = root(p);
      int j = root(q);

      if (sizes[i] < sizes[j]) {
        entries[i] = j; // connect the smaller to the larger root
        sizes[j] += sizes[i]; // update the size of sizes[j] to reflect the update above.
      } else {
        entries[j] = i;
        sizes[i] += sizes[j];
      }
      sets--;
    }

    bool connected(int p, int q) {
      return entries[q] == p;
    }

    void print() {
      cout << "[";
      for (int i = 0; i < n; i++) {
        cout << i << "=" << entries[i] << ", ";
      }
      cout << "] Sets=" << sets << endl;
    }

    ~QuickUnion() {
      delete [] entries;
      cout << "Deleted array " << endl;
    }
    int size() {
      return n;
    }
};

int main() {
  cout.setf(ios::boolalpha);
  QuickUnion qu (10);
  qu.print();
  qu.connect(0, 1);
  qu.print();
  cout << "Are 0,1 connected: " << qu.connected(0, 1) << endl;
  qu.connect(8, 9);
  qu.print();
  qu.connect(0,8);
  qu.print();
  return 0;
}
