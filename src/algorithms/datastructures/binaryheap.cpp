#include <iostream>

/*
 * Keys are stored in an array so that each key is guaranteed to be
 * larger or equal to they keys at two other specific positions.
 *
 * To move around we use the following calculations:
 * - Root not is 1
 * - Parent of a node k is k/2
 * - Children of node k are 2k and 2k+1
 *
 * (The largest index is the root which is 1 not 0. 0 is empty make calculations simple)
 * So the root is in position 1 and its two children in 2 and 3.
 * Their children are in position 4,5 and 6,7 and so on:
 *               1 ()
 *                /  \
 *             2()   3()
 *             / \    / \
 *          4() 5() 6() 7()
 *
 * Find parent (k/2):
 * Parent of 4 = floor(4 / 2) = 2
 * Parent of 5 = floor(5 / 2) = 2
 *
 * Find child (left: k2, right: k2+1):
 * Left child of 2  = 2 * 2 = 4
 * Right child of 2 = 2 * 2 = 1 = 5
 *
 * To move from k we simply set a[k/2]
 *
 * Binary heap structurs allow us to implement logarithmic-time insert
 * and remove the max methods. 
 *
 * The height of the tree only increases when the tree is incremented
 * to become a power of two:
 * 1^0 = 1
 * 2^1 = 2
 * 2^2 = 4
 * 2^3 = 8
 * 2^4 = 16
 * 
 */
class BinaryHeap {
  private:
    int mcapacity;
    int n;
    char *a;
    /**
     * For an inserted value we need to keep the heap in order.
     * Rememeber that the order is that is that a node's value must
     * not be greater than it's parent's value.
     */
    void reheapifyUp(int k) {
      while (k > 1 && a[k] > a[k/2]) {
        swap(k/2, k, a);
        k = k/2;
      }
    }
  public:
    BinaryHeap() : mcapacity(10), n(0) {
      a = new char[mcapacity + 1];
    }
    ~BinaryHeap() {
      delete [] a;
    }
    static void swap(int i, int j, char *a) {
      char tmp = a[i];
      a[i] = a[j];
      a[j] = tmp;
    }
    /**
     * When we remove the max we also have to maintain the order. This time
     * going from the top of the heap.
     */
    static void reheapifyDown(int k, char *a, int n) {
      // Remember k*2 will give us the left child if there is one.
      while (k*2 <= n) {
        int child = 2*k;
        // We want to check if the parent's node value is smaller than one or both
        // of the children's values. Check which is the larger of the two children's
        // values and use the largest. We pick the larger value as this is the value
        // that will be moved up.
        if (child < n && a[child] < a[child+1]) {
          child++; // right child
        }
        if (a[k] > a[child]) {
          break;
        }
        swap(k, child, a);
        k = child;
      }
    }
    int capacity() {
      return mcapacity;
    }
    int size() {
      return n;
    }
    void insert(char c) {
      a[++n] = c; // insert into the next available slot in the array
      reheapifyUp(n);
    }
    char removeMax() {
      char m = max();
      a[1] = a[n];
      n--;
      reheapifyDown(1, a, n);
      return m;
    }
    char max() {
      return a[1];
    }
    void printArray() {
      std::cout << "a[";
      for (int i = 1; i < n; i++) {
        std::cout << a[i] << ",";
      }
      std::cout << a[n];
      std::cout << "]" << std::endl; 
    }
};
