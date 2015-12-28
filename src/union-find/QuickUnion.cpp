#include <iostream>

using namespace std;

class QuickUnion {
  private:
    int * entries;
    int * sizes;
    int n;
    int comps;

  public:

    QuickUnion(int n) {
      this->n = n;
      this->comps = n;
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
      comps--;
    }

    bool connected(int p, int q) {
      return root(p) == root(q);
    }

    void print() {
      cout << "[";
      for (int i = 0; i < n; i++) {
        cout << i << "=" << entries[i] << ", ";
      }
      cout << "] Sets=" << comps << endl;
    }

    ~QuickUnion() {
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
