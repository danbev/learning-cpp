/*
 * This class is just for helping me understand linking issues
 * related to undefined symbols
 * Compiling (will generate the error):
 * $ clang++ -o missing  missing-vtable.cpp --save-temps
 *
 * $ otool -tvV missing-vtable.o
 * $ nm missing-vtable.o
 * 0000000000000030 S __ZN5DummyC1Ev
 * 0000000000000050 S __ZN5DummyC2Ev
 *                  U __ZTV5Dummy
 * 0000000000000000 T _main
 * S = The symbol is in an uninitialized data section for small objects.
 * U = The symbol is undefined. 
 * T = The symbol is in the text (code) section.
 *
 * All C++ name mangeled symbols start with __Z. 
 * Next comes the N followed by a series of length, id pairs.
 * C1 = Constructor
 * C2 = base object constructor
 * E  = end nested
 * v  = void
 *
 * "a missing vtable usually means the first non-inline virtual member function has no definition"
 *
 */
class Dummy {
    //virtual void doit();
    virtual void doit();
};

// there is no implementation of the virtual method doit.
// comment out this definition to produce the error
/*
void Dummy::doit() {
}
*/

int main(int argc, char **argv) {
    Dummy d;
}

