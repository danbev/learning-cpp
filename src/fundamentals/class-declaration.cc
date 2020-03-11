
class Something {
 public:
  class Map doit() const;
};

class Map Something::doit() const {
  return Map();
}

class Map {};

int main(int argc, char** argv) {
  int Something = 10;
  class Something s{};
  s.doit();

}
