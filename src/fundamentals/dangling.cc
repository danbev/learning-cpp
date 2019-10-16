#include <cstdio>

class Class {
  public:
   Class(int nr) : nr_(nr) {} 
   ~Class() { 
     fprintf(stderr, "Deleting Class nr_ = %d\n", nr_); 
     nr_ = -1;
   }
   int nr_;
   void printnr() {
     fprintf(stderr, "%p, nr_= %d\n", this, nr_); 
   }
};

int main(int argc, char** argv) {
   fprintf(stderr, "Main...\n");
   Class* c = new Class(10);
   Class* c2 = c;
   delete c;
   c2->printnr();
   c->printnr();
}
