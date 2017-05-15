template <typename T>
class TemplateClass {
 public:
  TemplateClass(T type);
  T get();
  void print();
  void usage();
  static void staticPrint(T type);
 private:
  T type_;
};
