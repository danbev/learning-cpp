#include <iostream>

/*
 * Triangular array
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
    TriArr(const unsigned int rows) {
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
        std::cout << "row was smaller than columns so we switch them!" << std::endl;
        return size(column) + row;
      }
      return size(row) + column;
    }
    void add(int row, int column, int value) {
      std::cout << "Adding to row=" << row << ", colum=" << column << ", value=" << value << std::endl;
    }

    friend std::ostream & operator<<(std::ostream &os, const TriArr &tri) {
      os << "TriArr[n=" << tri.n;
      return os;
    }
};

