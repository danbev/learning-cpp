#include <iostream>

class Options {
 public:
  enum Option : bool { Exit = true, DontExit = false };
  explicit Options(Option option = Exit, const char* usage = nullptr) : option_(option), usage_(usage) {}

  static Options exit(const char* usage = nullptr) {
    return Options(Exit, usage);
  }
  static Options dontExit(const char* usage = nullptr) {
    return Options(DontExit, usage);
  }

 private:
   const char* usage_;
   Option option_;
};

void something(Options options) {
}

int main(int argc, char** argv) {

  Options default_options;
  Options exit = Options::exit();
  Options dont_exit = Options::dontExit();

  something(default_options);
  something(Options(Options::Exit, nullptr));

}
