## Learning C++11 
The sole purpose of this project is to learn C++11 and techniques around setting up a project for C++11. 


### Building
This project uses Autotool and is required to bulid

    autoreconf --install
    ./configure CPPFLAGS=-DGTEST_USE_OWN_TR1_TUPLE=1
    make

#### Manually compiling a program
Compiling with c++11 and libc:

    clang++ -std=c++11 -stdlib=libc++ types.cpp -o types

To add multiple object files:

    clang++ -std=c++11 -stdlib=libc++ -lstdc++ -L. sorting.cpp -o sorting sort.o

Mergesort:

    clang++ -std=c++11 -stdlib=libc++ -lstdc++ -L. mergesort.cpp -o mergesort sort.o

### Running tests

    make check

You can run individual test by running them directly:

    ./test/linkedlist_test --gtest_filter=linkedlist.contains

To list all the tests:

    ./test/linkedlist_test --gtest_list_tests

You can also run the test directly:

  ./test/.libs/mergesort_test

#### Disabling a test
You can disable a test by renaming it with a ```DISABLED_``` prefix, as in:

```
TEST(BinaryHeap, DISABLED_insert) {
...
}
```

### Debugging

    lldb test/.libs/mergesort_test

    (lldb) breakpoint set --line 41
    (lldb) breakpoint set --file mergesort.cpp --line 33
    (lldb) run

Show frame variables:

    (lldb) frame variable
    (lldb) fr v

Show current source:

    (lldb) source list
or
    (lldb) frame select

Source step:

    (lldb) thread step-in
    (lldb) s
    (lldb) thread step-over
    (lldb) n
    (lldb) thread step-out
    (lldb) finish

Show frames:

    (lldb) thread backtrace
    (lldb) bt

A useful argument is --count which limits the backtrace, for example:

    (lldb) br -c 3


This can be useful when inspecting recursive algorithms. For example, mergesort may look something like this:

    (lldb) thread backtrace
    * thread #1: tid = 0x173e0, 0x0000000100000d4b mergesort`mergeSort(arr=0x00007fff5fbff620, len=4, aux=0x00007fff5fbff5c0, low=0, high=0) + 27 at mergesort.cpp:23, queue = 'com.apple.main-thread', stop reason = step in
      * frame #0: 0x0000000100000d4b mergesort`mergeSort(arr=0x00007fff5fbff620, len=4, aux=0x00007fff5fbff5c0, low=0, high=0) + 27 at mergesort.cpp:23
        frame #1: 0x0000000100000d92 mergesort`mergeSort(arr=0x00007fff5fbff620, len=4, aux=0x00007fff5fbff5c0, low=0, high=1) + 98 at mergesort.cpp:27
        frame #2: 0x0000000100000d92 mergesort`mergeSort(arr=0x00007fff5fbff620, len=4, aux=0x00007fff5fbff5c0, low=0, high=2) + 98 at mergesort.cpp:27
        frame #3: 0x0000000100000d92 mergesort`mergeSort(arr=0x00007fff5fbff620, len=4, aux=0x00007fff5fbff5c0, low=0, high=4) + 98 at mergesort.cpp:27
        frame #4: 0x0000000100000e42 mergesort`merge_sort(arr=0x00007fff5fbff620, len=4) + 98 at mergesort.cpp:34
        frame #5: 0x0000000100000eb7 mergesort`main + 71 at mergesort.cpp:41
        frame #6: 0x00007fff922575c9 libdyld.dylib`start + 1

Printing an array:

    (lldb) p *(int(*)[5]) arr

Saving breakpoints:  
Sometime you want to exit lldb and recompile to make change in the tested code. This means you hhave to reenter you breakpoints. But you can also specify command to run when lldb start using the ```-S filename``` argument:

  	lldb -S breakpoints test/.libs/pattern_test

Adding a conditional break point:  

    (lldb) breakpoint set --file heapsort.cpp --line 41 --condition 'end==1'

Here _end_ is a local variable.

Adding a watch point:  

    (lldb) watchpoint set var end

Every time the above variable _end_ is modified it will be displayed:

    Watchpoint 1 hit:
    old value: 2
    new value: 1

You can also add a condition so that it breaks when this condition applies:  

    (lldb) watchpoint modify -c 'end==1'
  

## Adding unit tests
You should be able to simply update the test/Makefile.am with the new test.  

## Troubleshooting
Unresolved symbol:
```shell
Undefined symbols for architecture x86_64:
  "IntIterator::next()", referenced from:
      Linkedlist_iterator_Test::TestBody() in linkedlist_test-linkedlist_test.o
  "IntIterator::hasNext()", referenced from:
      Linkedlist_iterator_Test::TestBody() in linkedlist_test-linkedlist_test.o
ld: symbol(s) not found for architecture x86_64
clang: error: linker command failed with exit code 1 (use -v to see invocation)
```
This was happening because int-iterator.h does not have any definitions of the methods
that it defines.
You can verify this by inspecting the unresolved symbols using `nm`:
```shell
$ nm -u test/algorithms/datastructures/linkedlist_test-linkedlist_test.o
__Unwind_Resume
__ZN11IntIterator4nextEv
__ZN11IntIterator7hasNextEv
...
```
Lets just try adding an inline definition to see if that make it resolved. Yep that worked but this is not what I want. I want the implementation to be different depending on the underlying data structure used for the iterator.
It turns out that I was trying to return an abstract class from my iterator() methods. This is not possible but I should have been returning a pointer or a reference. Thinking about this a little more it makes sense, to return a non-reference requires instantiating a ny instance but that won't work as the class is abstract.


### Adding Google test to the project

#### Build the gtest lib:

    $ mkdir lib
    $ mkdir deps ; cd deps
    $ git clone git@github.com:google/googletest.git
    $ cd googletest/googletest
    $ mkdir build ; cd build
    $ clang -I`pwd`/../include -I`pwd`/../ -pthread -c `pwd`/../src/gtest-all.cc
    $ ar -rv libgtest.a gtest-all.o
    $ cp libgtest.a ../../../../lib

#### Writing a test file

    $ mkdir test
    $ vi main.cc
    #include "gtest/gtest.h"
    
    int main(int argc, char* argv[]) {
      ::testing::InitGoogleTest(&argc, argv);
      return RUN_ALL_TESTS();
    }

    $ vi context_test.cc
    #include "gtest/gtest.h"

    TEST(Context, test) {
    }

And then compile using:
    
    $ clang++ -I`pwd`/../deps/googletest/googletest/include -pthread main.cc ../lib/gtest/libgtest.a -o context_test

Run the test:
    
    ./context_test

### Destructors
C++ specifies that when a derived class object is deleted through a pointer to a base class with a non-virtual destructor, results are undefined.
What typically happens at runtime is that the derived part of the object is never destroyed.


### Templates

#### Instantiation
This is the process were the compiler will generate a specialization of the template, for example create
/compile a function that take concrete types.
This can be implicit/automatic which is when there is a usage of the template. Note that is usage
and not just a declaration of a pointer to the template.


### Plain Old Data
Is a struct or a class without constructors, destructors, or any virtual member functions.
Member variables declared later in a structure must be at higher addresses. These types of objects are compatible with C.
You can check if a type is a POD using:

    std::is_pod<Type>();

Recall that the only different in C++ between a struct and a class is the default access of members. For a struct the default
is public, but for a class the default is private. This makes sense if you think of a class which is supposed to expose an 
interface and hide its members. The interface for a struct is its data members.

If a struct or class inherits from another, for exemple

    struct Derived : public Base {
    }

Adding member functions to a struct/class (non-virtual) does not effect the size of the struct class. The reason for this
is that the compiler transforms the function to a free (not tied to the class/struct) which takes a this pointer as its
first argument. It also name mangles this function and at the call site passes in the this argument

## Symbols
This section takes a closer look at what an object file looks like and the sybols it uses. 
The sources files are located in src/fundamentals and are symbols and symbols-main.cc.

    #include "symbols.h"

    int main(int argc, char* argv[]) {
      Something s{8};
      return 0;
    }

Lets take a look at the symbols for symbols.h:

    $ objdump -D symbols.o

    symbols.o:file format Mach-O 64-bit x86-64

But if we look at symbols-main.o we get:

    $ nm symbols-main
    0000000100000f70 t __ZN9SomethingC1Ei
    0000000100000fa0 t __ZN9SomethingC2Ei
    0000000100000000 T __mh_execute_header
    0000000100000f30 T _main
                 U dyld_stub_binder

The first entry is the addresses of the symbols.
The second column is where the symbol is located.

`t` means that the symbol is only visible within this file.
`T` means that the symbol is in the text/code section.
`D` means that the symbol is in the data section.
'U' means that the symbol is undefined and will be attempted to be resolved at runtime.

The third colum is the name of the mangled symbol.
`__Z` is just a prefix
`N` nested ?.
`9Something` this is length of the function name followed by the function name. 
`C1` complete object constructor
`C2` base object constructor
`E` end nested ?
`i` parameters `int`

Construtor/destructor values:
C1 complete object constructor
C2 base object constructor
C3 complete base allocating constructor
D0 deleting constructor
D1 complete object destructor
D2 base object destructor

What is a base object constructor?
G++ emits two copies of constructors and destructors.

In general there are three types of constructors (and destructors).
1. The complete object constructor/destructor.
It additionally constructs virtual base classes.

2. The base object constructor/destructor.
It creates the object itself, as well as data members and non-virtual base classes.

3. The allocating constructor/deallocating destructor.
It does everything the complete object constructor does, plus it calls operator new to actually allocate the memory

The first two are different, when virtual base classes are involved.
If you have no virtual base classes, [the first two] are are identical; GCC will, on sufficient optimization levels, actually alias the symbols to the same code for both.

    $ c++filt __ZN9SomethingC1Ei
    Something::Something(int)

    $ c++filt __ZN9SomethingC2Ei
    Something::Something(int)

Are there two symbols for the constructor, what is going on?
Well, remember that when we compiled these we used:
    
    $ clang++ -I. symbols.o symbols-main.cc -o symbols-main --std=c++11

To inspect the text section:
```console
$ otool -Vt symbols-main
symbols-main:
(__TEXT,__text) section
_main:
0000000100000f30  pushq%rbp
0000000100000f31  movq%rsp, %rbp
0000000100000f34  subq$0x20, %rsp
0000000100000f38  leaq-0x18(%rbp), %rax
0000000100000f3c  movl$0x8, %ecx
0000000100000f41  movl$0x0, -0x4(%rbp)
0000000100000f48  movl%edi, -0x8(%rbp)
0000000100000f4b  movq%rsi, -0x10(%rbp)
0000000100000f4f  movq%rax, %rdi
0000000100000f52  movl%ecx, %esi
0000000100000f54  callq__ZN9SomethingC1Ei ## Something::Something(int)
0000000100000f59  xorl%eax, %eax
0000000100000f5b  addq$0x20, %rsp
0000000100000f5f  popq%rbp
0000000100000f60  retq
0000000100000f61  nopw%cs:(%rax,%rax)

__ZN9SomethingC1Ei:
0000000100000f70  pushq%rbp
0000000100000f71  movq%rsp, %rbp
0000000100000f74  subq$0x10, %rsp
0000000100000f78  movq%rdi, -0x8(%rbp)
0000000100000f7c  movl%esi, -0xc(%rbp)
0000000100000f7f  movq-0x8(%rbp), %rdi
0000000100000f83  movl-0xc(%rbp), %esi
0000000100000f86  callq__ZN9SomethingC2Ei ## Something::Something(int)
0000000100000f8b  addq$0x10, %rsp
0000000100000f8f  popq%rbp
0000000100000f90  retq
0000000100000f91  nopw%cs:(%rax,%rax)

__ZN9SomethingC2Ei:
0000000100000fa0  pushq%rbp
0000000100000fa1  movq%rsp, %rbp
0000000100000fa4  movq%rdi, -0x8(%rbp)
0000000100000fa8  movl%esi, -0xc(%rbp)
0000000100000fab  movq-0x8(%rbp), %rdi
0000000100000faf  movl-0xc(%rbp), %esi
0000000100000fb2  movl%esi, (%rdi)
0000000100000fb4popq%rbp
0000000100000fb5retq
```
If we look at:
  
    324 0000000100000f54callq__ZN9SomethingC1Ei ## Something::Something(int)

And if we look at __ZN9Something we can see it calls:

    338 0000000100000f86callq__ZN9SomethingC2Ei ## Something::Something(int)



