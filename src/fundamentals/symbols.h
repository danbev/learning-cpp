// $ clang++ -c -o symbols.o symbols.cc --std=c++11
class Something {
  public:
    Something(int number) : number_(number) {};
    ~Something() = default;
    int getNumber() const {
      return number_;
    }
  private:
    int number_;
};
