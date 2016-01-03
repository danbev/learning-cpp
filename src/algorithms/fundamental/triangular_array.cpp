#include <iostream>

/*
 * Triangular array example which is a way to save space
 * For example:
 *               Chicago   NY        LA        San Fran
 *  Chicago     {0,       790,      1745,     1852},
 *  New York    {790,       0,      2776,     2564},
 *  LA          {1745,    2776,        0,      381},
 *  San Fran    {1852,    2564,       381,       0}
 * };
 * All 0 are redudant. So 4 entries could be removed.
 *
 *                Chicago   NY        LA        San Fran
 *   Chicago      {-,       790,      1745,     1852},
 *   New York     {790,       -,      2776,     2564},
 *   LA           {1745,    2776,        -,      381},
 *   San Fran     {1852,    2564,       381,       -}
 * All have double refs to each other,
 * LA-NY and NY-LA, so more entries can be removed:
 *
 *                Chicago   NY        LA        San Fran
 *   Chicago      {-,        --,         -,        -},
 *   New York     {790,       -,         -,        -},
 *   LA           {1745,    2776,        -,        -},
 *   San Fran     {1852,    2564,       381,       -}
 * So we can see that the whole first line can be removed. Also note how we have removed
 * all entries with a line through the diagonal.
 * So, for a 4 row two dimentional array we have removed:
 * 4 + 3 + 2 + 1 = 10 entries. The original size was 16 so we need to create an array of 6.
 * This can be calculated using:
 * N * (N-1)/2
 */
class TriArr {
  private:
    int *arr;
    unsigned int orgRows;
    unsigned int n;
    int size(int rows) {
      return rows * (rows - 1) / 2;
    }
  public:
    TriArr(unsigned int rows) {
      this->orgRows = rows;
      this->n = size(rows);
      std::cout << "Creating array with size: " << n << std::endl;
      arr = new int[n];
    }
    ~TriArr() {
      delete [] arr;
    }
    int length() {
      return n;
    }
    int index(unsigned int row, unsigned int column) {
      if (row < column) {
        return size(column) + row;
      }
      return size(row) + column;
    }
    void set(unsigned int row, unsigned int column, int value) {
      arr[index(row, column)] = value;
      std::cout << "Adding to row=" << row << ", column=" << column << ", value=" << value << " index=" << index(row, column) << std::endl;
    }
    int get(unsigned int row, unsigned int column) {
      return arr[index(row, column)];
    }
    friend std::ostream & operator<<(std::ostream &os, const TriArr &tri) {
      os << "TriArr[n=" << tri.n;
      return os;
    }
};

