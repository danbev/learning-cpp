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
    #include "context_test.cc"
    
    int main(int argc, char* argv[]) {
      ::testing::InitGoogleTest(&argc, argv);
      return RUN_ALL_TESTS();
    }

    $ vi context_test.cc
    #include "gtest/gtest.h"

    TEST(Context, test) {
    }

Add the test as an include in main.cc, and then compile using:
    
    $ clang++ -I`pwd`/../deps/googletest/googletest/include -pthread main.cc ../lib/gtest/libgtest.a -o context_test

Run the test:
    
    ./context_test

### Destructors
C++ specifies that when a derived class object is deleted through a pointer to a base class with a non-virtual destructor, results are undefined.
What typically happens at runtime is that the derived part of the object is never destroyed.
