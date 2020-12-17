#include <unistd.h>
#include <cstdio>


class RedirectStdErr {
 public:
  RedirectStdErr(const char* filename) : filename_(filename) {
    fflush(stderr);
    fgetpos(stderr, &pos_);
    fd_ = dup(fileno(stderr));
    freopen(filename_, "w", stderr);
  }

  ~RedirectStdErr() {
    fflush(stderr);
    dup2(fd_, fileno(stderr));
    close(fd_);
    remove(filename_);
    clearerr(stderr);
    fsetpos(stderr, &pos_);
  }

 private:
  int fd_;
  fpos_t pos_;
  const char* filename_;

};

int main(int argc, char** argv) {
  fprintf(stderr, "before...\n");
  {
    RedirectStdErr scope("tmp");
    fprintf(stderr, "in scope...\n");
  }
  fprintf(stderr, "after scope...\n");
}
