
class Something {
 public:
   constexpr Something(int x) : x_(x) {}
   int x_;
};

constexpr Something one = Something(1);
constexpr Something two = Something(2);
