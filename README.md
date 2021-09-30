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

### C++ Standard API
https://gcc.gnu.org/onlinedocs/libstdc++/latest-doxygen/index.html

Since I'm using clang and it has its own [version](http://libcxx.llvm.org/docs/) of the standard C++
library.

The headers are availabe on my system in [/usr/include/c++/4.2.1/](/usr/include/c++/4.2.1/) and the
source code can be found [here](https://github.com/llvm-mirror/libcxx).


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


Watch read and writes:

    (lldb) wa s v --watch read_write mp->nm_modname

Creating variables:
If you prefix a variable with $ you can use it in future commands, for example:

    (lldb) expr -- int* $d = new int{20}
    (lldb) expr $d
  

Calling a function:
    (lldb) expr -- printf("bajja\n")

#### Show local variable that clashes with global
Say you have a function that takes a parameter named args. If you try to print the
value of it you'll get:
```console
$ (lldb) expr args
error: reference to 'args' is ambiguous
candidate found by name lookup is 'args'
candidate found by name lookup is 'args'
candidate found by name lookup is 'args'
```
To work around this you can:
```console
(lldb) fr v args
(const char *const [4]) args = ([0] = "../src/tcp_wrap.cc", [1] = "146", [2] = "args.IsConstructCall()", [3] = "static void node::TCPWrap::New(const FunctionCallbackInfo<v8::Value> &)")
(lldb) fr v args[0]
(const char *const) args[0] = 0x0000000102620641 "../src/tcp_wrap.cc"
(lldb) fr v args[3]
(const char *const) args[3] = 0x000000010262077c "static void node::TCPWrap::New(const FunctionCallbackInfo<v8::Value> &)"
```

#### Add command on breakpoint
```console
(lldb) br s -n somebreakpoint
(lldb) br command add 1.1
> expr timer_
DONE
```

Alternative to adding print statements.
```console
(lldb) br s -f node_quic_util.h -l 461 -C 'frame info' -C 'expr *this' -C continue
```
Sometimes it can be needed to have print statements if the
issue/bug is timing dependent.

Running a shell command from within lldg:
```console
(lldb) platform shell find ../v8_src/v8 -name v8.cc
```

#### Adding aliases
```console
(lldb) command alias beve br s -f %1 -l %2 -C 'expr %4' -C continue
```

#### Print/echo something in command/script
```console
(lldb) script print "something"
```

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


### Function members
When you have a function as a member of a class or a struct the compiler will generate "free" functions. These
are functions that are not part of the class/struct and don't effect the size of the class.

    int Something::doit() const {
       return some;
    }

    Something s{};
    int result = s.doit();

The compiler will insert this:

    int Something::doit(Something* this) const {
       return some;
    }

And since the function is const:

    int Something::doit(Something const* const this) {
       return this->some;
    }

At the call site/function invocation:

    int result = doit(&s);

The function itself will be name mangled and the function invocation name will also be updated with
this name.

### CV-Qualifiers (Const and Volatile)
These are type qualifiers.
const makes the type constant and it cannot be modified. For a pointer it means the pointer cannot point
to anything else, but what is pointed to might be non-const.

#### volatile
Tells the compiler that it cannot optimize read/writes to a variable as it might change by some
means unknow to the compiler. Lets say that we have an int set in our program and there is no
code that changes it (that the compiler can detect). The compiler might avoid fetching the value
from memory and this might not be what you want.


## Symbols
This section takes a closer look at what an object file looks like and the symbols it uses. 
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
```
`t` means that the symbol is only visible within this file.
`T` means that the symbol is in the text/code section.
`D` means that the symbol is in the data section.
'U' means that the symbol is undefined and will be attempted to be resolved at runtime.
```

The third colum is the name of the mangled symbol:
```
`__Z` is just a prefix
`N` is nested inside a scope of a namespace or a class
`9Something` this is length of the function name followed by the function name. 
`C1` complete object constructor
`C2` base object constructor
`E` end nested (namespace or class).
`i` parameters `int`
```

Construtor/destructor values:
```
C1 complete object constructor
C2 base object constructor
C3 complete base allocating constructor
D0 deleting constructor
D1 complete object destructor
D2 base object destructor
```

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



## const
There is a [const_test.cc](./test/fundamentals/const_test.cc) for referense regarding using const. 

#### Const pointer
Is a pointer that cannot changed the address it holds:

    <type of pointer>* const <variable name>


#### Pointer to const
Is a pointer that cannot change the value it points to.

    const <type of pointer>* <variable name>
    <type of pointer> const* <variable name>

Notice that const always comes before the *.

const can go before or after after the type:

    const T t;
    T const t;

`t` is of type const int.

The above are the same as is the following example with int data type:

    int const number = 10;
    const int number = 10;

One thing to note is when using const with pointers and where you put the const.
This determines if you want the pointer to be const or the thing the pointer is 
pointing to to be const.

Pointer to const:

    int const* number;

`number` is of type pointer to const int.

    const int* number;

Here the pointer is not const but what it points to is (int const).

Const pointer to variable you have to put const after the *:

    int* const number;
   
`number` a pointer to a const int. The pointer can be updated to point elsewhere but what it points to 
cannot change.

### Strings
A `std::string` usually stores a pointer to a location on the heap. It also
needs to store the `size` of the data, and the `capacity`.

So: 
```
size = the length of the string.
capacity = how many chars the string can hold before it has to allocate a new, larger buffer from the heap.
data = pointer to the char array.
```

Some implementations allow for storing strings as local variables on the stack
(not too large though as that might overflow the stack). This is called Small 
String Optimization. In this case there would be a char[20] for example.

Lets take a look at the following string:

    #include <string>
    ...
    std::string s{"bajja"};

How does the compiler interpret this?
What is `std::string` actually?
I believe it is a template in `/usr/include/c++/4.2.1/bits/stringfwd.h`:

    typedef basic_string<char> string;

And what then is basic_string? :

    template<typename _CharT, typename _Traits = char_traits<_CharT>,
             typename _Alloc = allocator<_CharT> >
      class basic_string;

    template<> struct char_traits<char>;
    template<class _CharT> struct char_traits;
    template<typename _Alloc> class allocator;

If we now run nm this (see [string-type.cc](./src/fundamentals/string-type.cc)) we find:

    $ nm string-type
    0000000100000f40 t __ZNSt3__111char_traitsIcE6lengthEPKc
                 U __ZNSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6__initEPKcm
                 U __ZNSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEED1Ev
    0000000100000000 T __mh_execute_header
    0000000100000e80 T _main
                 U _memset
                 U _strlen
                 U dyld_stub_binder

    $ c++filt __ZNSt3__111char_traitsIcE6lengthEPKc
    std::__1::char_traits<char>::length(char const*)

    $ c++filt __ZNSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6__initEPKcm
    std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >::__init(char const*, unsigned long)

    $ c++filt __ZNSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEED1Ev
    std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >::~basic_string()

So `/usr/include/c++/4.2.1/string` includes `bits/char_traits.h` and `bits/basic_string.tcc` (t = template, cc = c++ source).

    (lldb) set set target.process.thread.step-avoid-regexp ""
    (lldb) 
    (lldb) s
    Process 91451 stopped
    * thread #1: tid = 0x2a8e37, 0x0000000100000eb9 string-type`main [inlined] std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >::basic_string(this="�_�\x7f\0\0\x01\0\0\0\0\0\0\0\x98�_�\x7f\0\0\x98�_�\x7f\0\0\x01\0\0\0\0\0\0\0�\x0f\0\0\x01\0\0\0\b�_�\x7f\0\0\0\0\0\0\0\0\0\0\0", __s="bajja") at string:2019, queue = 'com.apple.main-thread', stop reason = step in
        frame #0: 0x0000000100000eb9 string-type`main [inlined] std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >::basic_string(this="�_�\x7f\0\0\x01\0\0\0\0\0\0\0\x98�_�\x7f\0\0\x98�_�\x7f\0\0\x01\0\0\0\0\0\0\0�\x0f\0\0\x01\0\0\0\b�_�\x7f\0\0\0\0\0\0\0\0\0\0\0", __s="bajja") at string:2019
       2016 template <class _CharT, class _Traits, class _Allocator>
       2017 inline _LIBCPP_INLINE_VISIBILITY
       2018 basic_string<_CharT, _Traits, _Allocator>::basic_string(const value_type* __s)
    -> 2019 {
       2020    _LIBCPP_ASSERT(__s != nullptr, "basic_string(const char*) detected nullptr");
       2021    __init(__s, traits_type::length(__s));
       2022 #if _LIBCPP_DEBUG_LEVEL >= 2

We can see that traits_type::length(__s) is being called so the compiler must generate a specialization for it which it did:

    std::__1::char_traits<char>::length(char const*)

And then we hvae the call to __init:

    std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >::__init(char const*, unsigned long)

The last symbol is for destructor/deallocator. Need to understand allocators work.

I've been wondering about `std::__1` and where it comes from?
In `/src/string.cpp` where have the following namespace declaration:

    _LIBCPP_BEGIN_NAMESPACE_STD

In `include/__config` we find:

    #define _LIBCPP_BEGIN_NAMESPACE_STD namespace std {inline namespace _LIBCPP_NAMESPACE
    #define _LIBCPP_NAMESPACE _LIBCPP_CONCAT(__,_LIBCPP_ABI_VERSION)
    #define _LIBCPP_ABI_VERSION 1

So this is an inline namespace used for versioning in libc++.

### Inline namespaces
Is a namespace that automatically exports all symbols to the parent namespace.
Examples can be found in [inline-ns](./src/fundamentals/inline-ns).

There is an example that demonstrates versioning, where one can move from an
older version to newer version by adding inline namespaces.

### std::Allocator
Was originally designed for near and far pointers that were used in the segmented memory model that Intel used to have.
Near and far pointer were removed from the C++ spec but std::allocator was not.

std::Allocator is the default memory allocator for the standard library containers.
They provide an interface to allocate, create, destroy, and deallocate objects. With allocators, containers and algorithms can be 
parameterized by the way the elements are stored. For example, you could implement allocators that use shared memory or that map the 
elements to a persistent database.

The purpose of the allocator is to allocate raw memory without construction of objects, as well as simply deallocate memory without 
he need to destroy them, hence the usage of operator new and operator delete directly is preferred over the usage of the keywords new 
and delete.

### new/delete

    A* a = new A;
    delete a;

The compiler will interpret that as:

    A* a = ::operator new(sizeof(A)); 
    a->A::A();
    if ( a != 0 ) {  // a check is necessary for delete
      a->~A();
      ::operator delete(a);
    }

You can declare `new` and `delete` yourself which we do in [stringsize.cc](./src/fundamentals/stringsize.cc).
One thing to not is that new does note only allocate memory, it also calls the constructor. And same with delete, it will
not only reclaim the memory but will first call the destructor.


### static_assert
Is a way to check a constant condition at compile time. For example:
```c++
static_assert(my_not<true>::value == false, "Compile time error if false");   
```
This could also be done prior to c++11 using `#error`. For example:
```c++
#if !defined(something) 
#error "something was not defined" 
#endif 
```

### Type traits
Were introduced with TR1 and extended with C++11 and provide a way to define
behaviour depending on types.

A type trait is a templated struct and its member variables give you information
about the type the type template is templated on.

A type trait provides a way to deal with the properties of a type. It is a template, which at
compile time yields a specific type or value based on one or more passed template arguments,
which are usually types.


    template<typename> struct is_pointer : public false_type { };
    _DEFINE_SPEC(1, is_pointer, _Tp*, true)

false_type is a typedef:

    typedef integral_constant<bool, false> false_type;

And integral_constant is a struct:

    template<typename _Tp, _Tp __v>
    struct integral_constant
    {
      static const _Tp                      value = __v;
      typedef _Tp                           value_type;
      typedef integral_constant<_Tp, __v>   type;
    };

Which would be specialized as:

    template<typename bool, bool false>
    struct integral_constant
    {
      static const bool                      value = false;
      typedef bool                           value_type;
      typedef integral_constant<bool, false> type;
    };

And that is what will be passed to the macro:

    _DEFINE_SPEC(1, is_pointer, _Tp*, true)

Just remember that this is a macro to `_Tp*` is passed into the next macro and does not refer
to a template parameter name. 

    #define _DEFINE_SPEC(_Order, _Trait, _Type, _Value)                  \
    // #define _DEFINE_SPEC(1, is_pointer, _Tp*, true)                   \
      _DEFINE_SPEC_##_Order##_HELPER(_Trait<_Type>, _Value)              \
    //_DEFINE_SPEC_1_HELPER(is_pointer<_Tp*>, true)                      \

    #define _DEFINE_SPEC_1_HELPER(is_pionter<_Tp*>, true)                \
      template<typename _Tp>                                             \
        struct _Spec                                                     \
        _DEFINE_SPEC_BODY(_Value)

    #define _DEFINE_SPEC_BODY(_Value)                                    \
    : public integral_constant<bool, _Value> { };



      _DEFINE_SPEC_##_Order##_HELPER(_Trait<_Type const>, _Value)        \
      _DEFINE_SPEC_##_Order##_HELPER(_Trait<_Type volatile>, _Value)     \
      _DEFINE_SPEC_##_Order##_HELPER(_Trait<_Type const volatile>, _Value)

    #define _DEFINE_SPEC_1_HELPER(_Spec, _Value)                         \
      template<typename _Tp>                                             \
        struct _Spec                                                     \
        _DEFINE_SPEC_BODY(_Value)

Header: /usr/include/c++/4.2.1/tr1/type_traits

#### enable_if
Take this example:

    template <typename T>
    typename std::enable_if<std::is_integral<T>::value, int>::type doit(T value) {
      std::cout << "template doit(...)" << '\n';
      return 1;
    }

So we can see that this is a templated function. What is new is the return type:
   
    typename std::enable_if<std::is_integral<T>::value, int>::type

So the compiler will try to match this function (it is overloaded) and substitute the
value passed in at the call site. Let say that was `doit(20)`.

Lets create our own enable_if:

    template <bool, typename T = void>
    struct _enable_if {
    };

    template <typename T>
    struct _enable_if<true, T> {
      typedef T type;
    }; 

I had some trouble understanding this but what is happening is that we have two structs
that are templated, one taking a bool and and a type, and the other taking the bool value
true and a type (with a default value). If the compiler while 

If we look at this:

    std::is_integral<T>::value

This will be substituted with either true or false depending on the type of T.

Lets look at the definition of `enable_if` (include/type_traits):

    template <bool, class T = void> struct enable_if;


### Substitution Failure Is Not An Error (SFINAE)
Take a look at [enable-if.cc](./src/fundamentals/enable-if.cc) and the third overloaded 
function. This is invalid code if there is a call like `doit(10)`:

    template <typename T>
    typename T::value_type doit(T value) {
      return value;
    };

int does not have a value_type so that should be a compile time error. When the compiler looks
for a match it has to substitute T with int but type decuction will fail but no error will
occur and instead the compiler will continue looking for a match.

### Types
Chart: http://howardhinnant.github.io/TypeHiearchy.pdf


### Signed vs unsigned
An int is signed by default, meaning it can represent both positive and negative values. 
An unsigned is an integer that can never be negative. If you take an unsigned 0 and subtract 1 from it, the result wraps around, leaving a very large number (2^32-1 with the typical 32-bit integer size).

Intuitively the two types seem to map fairly reasonably to mathematical notions of integers and natural numbers, leading many programmers to choose unsigned types for any values that "feel" like they should never be negative, such as loop indices or measurements of size. Unfortunately, this is not a reliable intuition.

size_t is unsigned so it can't represent negative
ssize_t is signed so it can represent negative

If you know that a ssize_t is greater than 0 you can safely cast it to a size_t because the
range of size_t is greater then the positive values of ssize_t


CHECK_EQ(static_cast<int32_t>(offset), offset);
```console
../src/stream_base.cc:295:3: warning: comparison of integers of different signs: 'int32_t' (aka 'int') and 'size_t' (aka 'unsigned long') [-Wsign-compare]
  CHECK_EQ(static_cast<int32_t>(offset), offset);
  ^        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~  ~~~~~~
```
```c++
void StreamBase::CallJSOnreadMethod(ssize_t nread,
                                    Local<ArrayBuffer> ab,
                                    size_t offset) {
  CHECK_EQ(static_cast<int32_t>(offset), offset);
```
So, we can see that `offset` is declared as `size_t` which is unsigned (can only represent positive values. We are checking that it can be casted to a `int32_t` which is a fixed integer type. 
Instead perhaps we can check that the offset is within the range without casting:
```c++
  CHECK_LE(INT32_MAX, offset);
```

### Memory
Accessing memory is not done on a byte basis. Instead computers compensate for slow memory access by fetching bigger chunks of data, for example 64 bytes 
at a time.


### decltype
The compiler tries to decuce types when is sees template. For example:

    template<typename T>
    void doit(T* something) {
    }
    ...
    const int a = 10;
    doit(a);

The compiler actually has to deduce the type for T and the type for something. The type of something
could have things like const or reference qualifiers. The way T is decuced depends on the parameters 
type.

### Casting

#### reinterpret_cast
Does compile to any CPU instruction and is just a compiler directive which instructs the compiler to threat
the sequence of bits as if it had the new type.


### sizeof
When sizeof's operand is a type, it has to be enclosed in parentheses. But when sizeof's operand is a variable, this is not required.
  
    sizeof expression
    sizeof(typename)

### Iterators




  std::string path() const {
    std::string ret;
    for (auto const& i : context_.path) {
      ret += '/';
      ret += i;
    }
    return ret;
  }


### nullptr

### Pointer to pointer
Lets say you have a function that needs to reassign a pointer that it is passed. 
If the function only takes a pointer to the object this is only a copy of the pointer:

    int* org =  new int{10};
    func(org);

    void fun(int* ptr) { ...};

Now, func will get a copy of org (pointing to the same int. But changing that 
pointer to point somewhere else does not affect But, if we pass a pointer to the 
org the we can update that value which will update our original as we are changing what it 
points to:

    void fun(int** ptr) { ...};



### Argument-dependant lookup (ADL)
The set or rules for looking up unquailified function names in function call expressions. It's about finding the correct function, 
and not about resolving the function parameters. 
The idea is that a function taking a user-defined type is often defined in the same namespace. So if the function is not found
in the context where it is is used, the namespace of the arguments will be searched.

### Unqualified name lookup
Is a name that does not use the `::` (scope resolution operator).
The look up will continue until the first resolution is done and then stop. Any name specified with the using directive
will be closest in scope when performing the lookup.

From the C++ specification:
```
8 For the members of a class X, a name used in a member function body, in a default argument, in a noexceptspecifier,
in the brace-or-equal-initializer of a non-static data member (12.2), or in the definition of a class
member outside of the definition of X, following the member’s declarator-id32, shall be declared in one of the
following ways:
(8.1) — before its use in the block in which it is used or in an enclosing block (9.3), or
(8.2) — shall be a member of class X or be a member of a base class of X (13.2), or
(8.3) — if X is a nested class of class Y (12.2.5), shall be a member of Y, or shall be a member of a base class of
Y (this lookup applies in turn to Y’s enclosing classes, starting with the innermost enclosing class),33 or
(8.4) — if X is a local class (12.4) or is a nested class of a local class, before the definition of class X in a block
enclosing the definition of class X, or
(8.5) — if X is a member of namespace N, or is a nested class of a class that is a member of N, or is a local class
or a nested class within a local class of a function that is a member of N, before the use of the name, in
namespace N or in one of N’s enclosing namespaces
```


### Node list implementation
I think the best way to look into this is to start with an example:
This is the data struture that we want to have a list of.
```c++
struct Something {
  Something() {
    std::cout << "Something() const..." << '\n';
  }
  ~Something() {
    std::cout << "~Something() const..." << '\n';
  }
  int data = 10;
  ListNode<Something> node_;
  };
```
Notice that we include a `ListNode<Something>` in the datastructure and the name of this member which
is `node_`. `ListNode` is a pretty simple class with takes a template type, which is `Something` in this
example:
```c++
template <typename T>
class ListNode {
 public:
  inline ListNode();
  inline ~ListNode();
  inline void Remove();
  inline bool IsEmpty() const;

 private:
  template <typename U, ListNode<U> (U::*M)> friend class ListHead;
  ListNode* prev_;
  ListNode* next_;
};
```
If we create an instancee of Something the default constructor for ListNode<Something> would be called:
```c++
ListNode<T>::ListNode() : prev_(this), next_(this) {}
```
At this point we would have something like this:
```
s {
  int data = 10;
  ListNode<Something> node_ = {
    prev_ = this; // The newly create ListNode
    next_ = this; // The newly create ListNode
  }
}
```

To create the list itself we could declare it somewhere like this:
```c++
  ListHead<Something, &Something::node_> list;
```
Something to note is the pointer to member that is being used, that is the `&Something::node_` syntax above. This is declared in ListHead like this:
```c++
template <typename T, ListNode<T> (T::*M)>
class ListHead {
  ...
};
```
```console
(lldb) expr
Enter expressions, then terminate with an empty line to evaluate:
  1: class T {
  2:   int data;
  3: };
  4: &T::data
  5:
(int T::*) $3 = 00 00 00 00 00 00 00 00
```
Notice the type of `$3` which is `T::*`. A pointer to member is not like a normal pointer, instead
if is an offset into the datastructure. So `data` in this case is the first member.
If we look again at our list:
```c++
  ListHead<Something, &Something::node_> list;
```
This would at compile time instantiate a class that looked like:
```c++
ListHead<Something, &Something::node_> {
 public:
    // skipping Iterator class for now

  inline ListHead() = default;
  inline ~ListHead();
  inline void PushBack(Something* element);
  inline void PushFront(Something* element);
  inline bool IsEmpty() const;
  inline Something* PopFront();
  inline Iterator begin() const;
  inline Iterator end() const;

 private:
  ListNode<Something> head_;
};
```
So, we see that we have a default constructor generated by the copiler and also a private 
member `head_` that will be initialized upon construction. 
```console
40    inline ListHead() = default;
(lldb) expr this
(ListHead<Something, 8> *) $9 = 0x00007fff5fbfe4d8

4     ListNode<T>::ListNode() : prev_(this), next_(this) {}
(lldb) expr this
(ListNode<Something> *) $10 = 0x00007fff5fbfe4d8
```
So at this stage we have a instance of the list and it's head_ member looks something like:
```c++
  ListNode<Something> head_ = {
    prev_ = this; // The newly create ListNode
    next_ = this; // The newly create ListNode
  }
```
So, lets push something into the back of the list:
```c++
  list.PushBack(&s);
```
```c++
template <typename T, ListNode<T> (T::*M)>
void ListHead<T, M>::PushBack(T* element) {
  ListNode<T>* that = &(element->*M);
  head_.prev_->next_ = that;
  that->prev_ = head_.prev_;
  that->next_ = &head_;
  head_.prev_ = that;
}
```
And we create `list` using:
```c++
ListHead<Something, &Something::node_> list;
```
```c++
void ListHead<Something, &Something::node_>::PushBack(Something* element) {
  ListNode<T>* that = &(element->*M);
  head_.prev_->next_ = that;
  that->prev_ = head_.prev_;
  that->next_ = &head_;
  head_.prev_ = that;
}
```
We can verify what `that` will be using:
```console
(lldb) expr element
(Something *) $15 = 0x00007fff5fbfe488

(lldb) expr &Something::node_
(ListNode<Something> Something::*) $18 = 08 00 00 00 00 00 00 00

(lldb) expr &(element->*&Something::node_)
(ListNode<Something> *) $19 = 0x00007fff5fbfe490

(lldb) expr that
(ListNode<Something> *) $20 = 0x00007fff5fbfe490
```
What we have done here is retrieved a reference to the `node_` member in the passed-in `element`.
We could inspect the contents of what it points to using:
```console
(lldb) expr element->*&Something::node_
(ListNode<Something>) $21 = {
  prev_ = 0x00007fff5fbfe490
  next_ = 0x00007fff5fbfe490
}
```
Next, we are going to add this new element to the back of the list. 
```c++
list.PushBack(&s);
```
The list starts out looking like this:
```
        +----------+       +------------+
   +--->|   head_  |       |    that    |<---+
   |    +----------+       +------------+    |
   +----|   prev_  |       |    prev_   |----+
   |    +----------+       +------------+    |
   +----|   next_  |       |    next_   |----+
        +----------+       +------------+
```

First thing that happens is
```c+++
head_.prev_->next_ = that;
```
```
        +----------+       +------------+
   +--->|   head_  |       |    that    |<---+
   |    +----------+       +------------+    |
   +----|   prev_  |       |    prev_   |----+
        +----------+       +------------+    |
        |   next_  |------>|    next_   |----+
        +----------+       +------------+
```
Next:
```c++
that->prev_ = head_.prev_;
```
```
        +----------+       +------------+
   +--->|   head_  |       |    that    |<---+
   |    +----------+       +------------+    |
   +----|   prev_  |<------|    prev_   |    |
        +----------+       +------------+    |
        |   next_  |------>|    next_   |----+
        +----------+       +------------+
```
Next:
```c++
that->next_ = &head_;
```
```       
             +-------------------------------+ 
             |                               |
        +----------+       +------------+    |
   +--->|   head_  |       |    that    |    |
   |    +----------+       +------------+    |
   +----|   prev_  |<------|    prev_   |    |
        +----------+       +------------+    |
        |   next_  |------>|    next_   |---->
        +----------+       +------------+
```
Next:
```c++
head_.prev_ = that;
```
```
             +-------------------------------+ 
   +---------|-------------------+           |
   |         |                   |           |
   |    +----------+       +------------+    |
   |    |   head_  |       |    that    |    |
   |    +----------+       +------------+    |
   <----|   prev_  |<------|    prev_   |    |
        +----------+       +------------+    |
        |   next_  |------>|    next_   |---->
        +----------+       +------------+
```
Let's add one more element:
```c++
list.PushBack(&s2);
```
```c++
head_.prev_->next_ = that;
```
```
             +-------------------------------+ 
   +---------|-------------------+           |
   |         |                   |           |
   |    +----------+       +------------+    |
   |    |   head_  |       |     s      |    |
   |    +----------+       +------------+    |
   <----|   prev_  |<------|    prev_   |    |
        +----------+       +------------+    |
        |   next_  |------>|    next_   |---->
        +----------+       +------------+
```


### lldb unresolved symbols
I sometimes find that I'm not able to display symbols when debugging, for example when trying to inspect a std::shared_ptr. This section shows one way to 
work around this. This example is taken from debugging node.

```console
(lldb) expr env.options()
(std::__1::shared_ptr<node::EnvironmentOptions>) $3 = std::__1::shared_ptr<node::EnvironmentOptions>::element_type @ 0x0000000105a01440 strong=3 weak=1 {
  __ptr_ = 0x0000000105a01440
}
(lldb) expr *env()->options_
error: Couldn't lookup symbols:
  __ZNKSt3__110shared_ptrIN4node18EnvironmentOptionsEEdeEv
```
```console
$ c++filt __ZNKSt3__110shared_ptrIN4node18EnvironmentOptionsEEdeEv
std::__1::shared_ptr<node::EnvironmentOptions>::operator*() const
```
So lldb cannot call this function is bascially what the above is saying. But we can see that the pointer address, `__ptr_` and perhaps we can simply cast that to the correcty
type:
```console
(lldb) expr (node::EnvironmentOptions*) 0x0000000105a01440
(node::EnvironmentOptions *) $1 = 0x0000000105a01440
(lldb) expr *$1
(node::EnvironmentOptions) $2 = {
  debug_options = std::__1::shared_ptr<node::DebugOptions>::element_type @ 0x0000000105a014f0 strong=2 weak=1 {
    __ptr_ = 0x0000000105a014f0
  }
  experimental_modules = false
  experimental_repl_await = false
  experimental_vm_modules = false
  experimental_worker = false
  expose_internals = false
  no_deprecation = false
  no_force_async_hooks_checks = true
  no_warnings = false
  pending_deprecation = true
  preserve_symlinks = false
  preserve_symlinks_main = false
  prof_process = false
  redirect_warnings = ""
  throw_deprecation = false
  trace_deprecation = false
  trace_sync_io = false
  trace_warnings = false
  userland_loader = ""
  syntax_check_only = false
  has_eval_string = false
  eval_string = ""
  print_eval = false
  force_repl = false
  preload_modules = size=0 {}
  user_argv = size=0 {}
}
```



### Lambda
A lambda 
```c++
class Functor {
 public:
  inline int operator()(int a) {
    return a + 3;
  }
};
```
The above should be the equivalent of creating a lambda. When the compiler finds a lambda it will create 
and instance of some lambda type (internal type) and it knows the operator() function and should be able to
inline it. 
But how can I be sure?


#### unordered_set
```c++
  std::unordered_set<CleanupHookCallback,
                     CleanupHookCallback::Hash,
                     CleanupHookCallback::Equal> cleanup_hooks_;
```
Just remember that an unordered set is templated with its key, 

### std::endl and std::flush
```c++
std::cout "something" << std::endl
```
This is the same as doing:
```c++
std::cout << '\n' << std::flush
```
Notice that we sending std::cout a char and not a string. If we instead passed
`"\n"` it would be forced to loop over all the characters looking for null.

Now, buffering can cause output to be delayed. The write system call (man 2 write)
```c
ssize_t write(int fildes, const void *buf, size_t nbyte);
```
This function takes a file descriptor and a bytebuffer and writes in the byte
buffer to the file decsriptor. Normal functions call are very fast but system
calls are not. Buffering exists to try to make this cost lower, so that the
actual call, with the context switch, is only done once the buffer is full.

File descriptors can be unbuffered, fully-buffered with a fixed size, or
line-buffered which means that it waits until it sees a newline character.
Line-buffered is what I've been interested in for programs that use std::endl
in combination with stdout/stderr.

stdin is line-buffered.
stdout (TTY) is line-buffered.
stdout (not a TTY) is fully-buffered.
stderr is line-buffered.

For line-buffered, data will be added to the buffer until a newline is encountered
which will cause a flush. Normally there will also be a max buffer size so with
either comes first.

TODO: Can we actually see where this is done, looking for a '\n' I mean?  
Well, the source code for libc++ is specific to the compiler, so GNU G++ would
have its own and llvm would have its. For llvm there is a github mirror named
llvm-project which I've cloned. 

The modes names are:
`_IOFBF` which is full-buffering  
`_IOLBF` which is line-buffering  
`_IONBF` which is no buffering  

The default streams stdin and stdout are fully buffered by default if they are
known to not refer to an interactive device. Otherwise, they may either be line
buffered or unbuffered by default, depending on the system and library
implementation. 
The same is true for stderr, which is always either line buffered or unbuffered
by default.

This can be and set using http://www.cplusplus.com/reference/cstdio/setvbuf/

### iostream
The "serial" nature of streams is a very important element of their interface.
You cannot directly make random access random reads or writes in a stream 
(unlike, say, using an array index to access any value you want) although you
can seek to a position in a stream and perform a read at that point.

class ios_base
This class has a number of static membersof type `fmtflags`
```c++
  typedef T1 fmtflags;
  tatic constexpr fmtflags boolalpha;
```
If we look in `iomanip` we have the following:
```c++
namespace std {

// types T1, T2, ... are unspecified implementation types
T1 resetiosflags(ios_base::fmtflags mask);
```

### I/O Manipulators (ios) and (iomanip)
Manipulators allow you to change flags using operator<< and operator>> instead
of flags(fmtflags) or setf()

```console
$ cd ~/work/llvm/llvm-project
$ mkdir build && cd build
$ cmake -DLLVM_ENABLE_PROJECTS='libxxc, clang' -DCMAKE_INSTALL_PREFIX=~/work/llvm/local_build -DCMAKE_BUILD_TYPE=Debug ../llvm
$ make -j8
$ make install

```console
$ clang++ -M main.cc
main.o: main.cc \
  /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/../include/c++/v1/iostream \
  /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/../include/c++/v1/__config \
  /usr/include/pthread.h \
  /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/../include/c++/v1/ios \
  /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/../include/c++/v1/iosfwd \
  /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/../include/c++/v1/wchar.h \
```

```console
-M, --dependencies
```


Building libcxx:
``console
$ mkdir build
$ cmake ..


There are automatic flushes that cover most use cases. For example, if a
program writes to the console, the system by default flushes after every newline.

### Preprocessor
Lets take a look at the output of the preprocessor using an empty main
function:
```
g++ -E preprocessor.cc 
# 1 "preprocessor.cc"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 1 "<command-line>" 2
# 1 "preprocessor.cc"

int main(int argc, char** argv) {
  return 0;
}
```

Show all the predefined macros (one that were not specified by us):
```console
$ touch empty.h
$ cpp -dM empty.h
```
`dM` will generate a list of #define directives for all the macros defined
during the preprocessor. 

```console
$ cpp  -dD empty.h 
# 1 "empty.h"
# 1 "<built-in>"
#define __STDC__ 1
#define __STDC_VERSION__ 201710L
#define __STDC_UTF_16__ 1
#define __STDC_UTF_32__ 1
#define __STDC_HOSTED__ 1
#define __GNUC__ 9
```
Reading the docs for cpp you might think that the format of these should
be:
```
# linenum filename flags
```
flags can be one of:
```
1) Indicates the start of a new file
2) Indicates the returning for an included file
3) That the text following comes from a system header so some warnings will be
supressed.
4) Specifies that the text following should be treated as being wrapped in
an implicit extern "C" block.


In which case `"<built-in>"` would be a file name, but this is on the case.
For example, if we add a variable on the command line:
```console
$ cpp -Dsomething=10 -dD empty.h 
cpp -Dsomething=10 -dD empty.h 
# 1 "empty.h"
# 1 "<built-in>"
#define __STDC__ 1
#define __STDC_VERSION__ 201710L
...
# 1 "<command-line>"
#define something 10
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 19 "/usr/include/stdc-predef.h" 3 4
#define _STDC_PREDEF_H 1
# 38 "/usr/include/stdc-predef.h" 3 4
#define __STDC_IEC_559__ 1







#define __STDC_IEC_559_COMPLEX__ 1
# 58 "/usr/include/stdc-predef.h" 3 4
#define __STDC_ISO_10646__ 201706L
# 1 "<command-line>" 2
# 1 "empty.h"
```

So where do these build-ins come from?  
If we look in libcpp and the `init.c` file we can find the following line:
```c
532     _cpp_define_builtin (pfile, "__STDC__ 1");                                  
```

So if we look in `vi +19 /usr/include/stdc-predef.h` we will find:
```c
 19 #define _STDC_PREDEF_H  1                                                       
```

### Global Constructors
These are functions that are called before the main function of our program and
not to be confused to C++ class constructors. There can be muliple constructors
that are to be run so they are stored as an array of function pointers.

Five objects files handle the program initialization and are called `crt0.o`,
`crti.o`, `crtbegin.o`, `crtend.o`, and crtn.o`.

crt0.o will contain the `_start` symbol which is the entry point.

Together these object files implement two functions: _init which runs the global
constructors and other initialization tasks, and _fini that runs the global
destructors and other termination tasks.

```console
$ ld crt0.o crti.o crtbegin.o sections.o crtend.o crtn.o
```

A global constructor in c can look like this:
```c
#include <stdio.h>

__attribute__ ((constructor)) void bajja(void) {
  printf("bajja is running\n");
}
 
int main(int argc, char** argv) {
  printf("%s: main...\n", argv[0]);
}
```
We can compile but not link this using:
```console
$ gcc -c -o global.o global.c 
```
And we can take a look at the section headers using objdump:
```console
$ objdump -h global.o -w

global.o:     file format elf64-x86-64

Sections:
Idx Name            Size      VMA               LMA               File off  Algn  Flags
  0 .text           00000040  0000000000000000  0000000000000000  00000040  2**0  CONTENTS, ALLOC, LOAD, RELOC, READONLY, CODE
  1 .data           00000000  0000000000000000  0000000000000000  00000080  2**0  CONTENTS, ALLOC, LOAD, DATA
  2 .bss            00000000  0000000000000000  0000000000000000  00000080  2**0  ALLOC
  3 .rodata         0000001e  0000000000000000  0000000000000000  00000080  2**0  CONTENTS, ALLOC, LOAD, READONLY, DATA
  4 .init_array     00000008  0000000000000000  0000000000000000  000000a0  2**3  CONTENTS, ALLOC, LOAD, RELOC, DATA
  5 .comment        0000002d  0000000000000000  0000000000000000  000000a8  2**0  CONTENTS, READONLY
  6 .note.GNU-stack 00000000  0000000000000000  0000000000000000  000000d5  2**0  CONTENTS, READONLY
  7 .eh_frame       00000058  0000000000000000  0000000000000000  000000d8  2**3  CONTENTS, ALLOC, LOAD, RELOC, READONLY, DATA
$ 
```
If we did not have a global constructor there would not be a `.init_array` and 
that it was added by the link editor. Since we only have a single global constructor
the size will be one 8 byte pointer. Adding a second would make it 16 (hex 10).

Now without an global constructors:
```console
$ objdump -h noglobal.o -w

noglobal.o:     file format elf64-x86-64

Sections:
Idx Name            Size      VMA               LMA               File off  Algn  Flags
  0 .text           0000002f  0000000000000000  0000000000000000  00000040  2**0  CONTENTS, ALLOC, LOAD, RELOC, READONLY, CODE
  1 .data           00000000  0000000000000000  0000000000000000  0000006f  2**0  CONTENTS, ALLOC, LOAD, DATA
  2 .bss            00000000  0000000000000000  0000000000000000  0000006f  2**0  ALLOC
  3 .rodata         0000000d  0000000000000000  0000000000000000  0000006f  2**0  CONTENTS, ALLOC, LOAD, READONLY, DATA
  4 .comment        0000002d  0000000000000000  0000000000000000  0000007c  2**0  CONTENTS, READONLY
  5 .note.GNU-stack 00000000  0000000000000000  0000000000000000  000000a9  2**0  CONTENTS, READONLY
  6 .eh_frame       00000038  0000000000000000  0000000000000000  000000b0  2**3  CONTENTS, ALLOC, LOAD, RELOC, READONLY, DATA
$ 
```
If we take a look at the linker script in use (ld --verbose) we can find that
these sections, `.init_array` are configured as follows:
```
 .init_array    :                                                              
  {                                                                             
    PROVIDE_HIDDEN (__init_array_start = .);                                    
    KEEP (*(SORT_BY_INIT_PRIORITY(.init_array.*) SORT_BY_INIT_PRIORITY(.ctors.*)))
    KEEP (*(.init_array EXCLUDE_FILE (*crtbegin.o *crtbegin?.o *crtend.o *crtend?.o ) .ctors))
    PROVIDE_HIDDEN (__init_array_end = .);                                      
  }                                         
```
The provide keyword defines a symbol, in this case `__init_array_start` which
is set to the address of this section.
When using the option `-gc-sections` which is link time garbage collection, keep
marks sections that are unused which would otherwise be removed. So this is saying keep all `.init_array`
sections in all input object files
```
    KEEP (*(SORT_BY_INIT_PRIORITY(.init_array.*) SORT_BY_INIT_PRIORITY(.ctors.*)))
```
This is in the output section `.init_array`, so we are specifying things that
will be added to that section in the ouput object file. These things are input
sections from the input object files (all of them). So in this case we want
to place all `.init_array.*` and `.ctors.*` into the output `.init_array` section.

The same goes for destructors, but the section name is then `.fini_array`.

We can take a look at the `.init_array` section and find the following:
```console
$ objdump -s -j .init_array global -w

global:     file format elf64-x86-64

Contents of section .init_array:
 403e00 30114000 00000000 36114000 00000000  0.@.....6.@.....
```
Notite that `403e00` is referenced in `__libc_csu_init`:
```
0000000000401190 <__libc_csu_init>:                                             
  401190:       f3 0f 1e fa             endbr64                                 
  401194:       41 57                   push   %r15                             
  401196:       4c 8d 3d 63 2c 00 00    lea    0x2c63(%rip),%r15        # 403e00 <__frame_dummy_init_array_entry>
```
So this is loading the address of the `.init_array` memory location that will
contain function pointers.


Lets try to figure out exactly what is going when we compile global.c:
```console
$ /usr/libexec/gcc/x86_64-redhat-linux/9/cc1 -quiet global.c -quiet -dumpbase global.c "-mtune=generic" "-march=x86-64" -auxbase global -o global.s
```
So this has generated an assembly source file named `global.s`.
Now, lets assemble it into an object file:
```console
$  as --64 -o global.o global.s
```
Next, we need to link this into an executable:
```console
$ /usr/libexec/gcc/x86_64-redhat-linux/9/collect2 -plugin /usr/libexec/gcc/x86_64-redhat-linux/9/liblto_plugin.so "-plugin-opt=/usr/libexec/gcc/x86_64-redhat-linux/9/lto-wrapper" "-plugin-opt=-fresolution=global.res" "-plugin-opt=-pass-through=-lgcc" "-plugin-opt=-pass-through=-lgcc_s" "-plugin-opt=-pass-through=-lc" "-plugin-opt=-pass-through=-lgcc" "-plugin-opt=-pass-through=-lgcc_s" --build-id --no-add-needed --eh-frame-hdr "--hash-style=gnu" -m elf_x86_64 -dynamic-linker /lib64/ld-linux-x86-64.so.2 -o global /usr/lib64/crt1.o /usr/lib64/crti.o /usr/lib/gcc/x86_64-redhat-linux/9/crtbegin.o -L/usr/lib/gcc/x86_64-redhat-linux/9 -L/usr/lib64 -L/lib64 -L/usr/lib64 -L/usr/lib global.o -lgcc --push-state --as-needed -lgcc_s --pop-state -lc -lgcc --push-state --as-needed -lgcc_s --pop-state /usr/lib/gcc/x86_64-redhat-linux/9/crtend.o /usr/lib64/crtn.o
```
TODO: what are these plugins?
TODO: understand collect2. collect2 wraps ld but I'm not exactly sure about the importance of it. 

```console
-o global /usr/lib64/crt1.o /usr/lib64/crti.o /usr/lib/gcc/x86_64-redhat-linux/9/crtbegin.o -L/usr/lib/gcc/x86_64-redhat-linux/9 -L/usr/lib64 -L/lib64 -L/usr/lib64 -L/usr/lib global.o -lgcc --push-state --as-needed -lgcc_s --pop-state -lc -lgcc --push-state --as-needed -lgcc_s --pop-state /usr/lib/gcc/x86_64-redhat-linux/9/crtend.o /usr/lib64/crtn.o
```
Notice that we have `crt1.o` and crti.o` from /usr/lib64, followed by `crtbegin.o`
from gcc. The we have our global.o followed by `crtend.o` and then `crtn.o`

Linking order:
```
crt1.0 crti.o crtbegin.o [-L paths] [user objs] [gcc libs] [c libs] crtend.o crtn.o 
```
crt1.o provides the `_start` entry point. 
`crti.o` provides the prologe for .init and .fini.
`crtbegin.o` is for gcc functions with __attribute__ ((constructor))
`crtend.o` is for gcc functions with __attribute__ ((destructor))
`crtn.o` is the epilouge for the .init and .fini functions.

The `init` section in an ELF object file contains executable instructions
for the initialization process. The dynamic linker will call this section
before code, and when it will call .fini when unloaded (via the exit() function
call I think).
Remember that when we execute a an object, we call execve and the operating
system will do stuff before checking the object for an interpreter:
```console
 objdump -s -j .interp global -w

global:     file format elf64-x86-64

Contents of section .interp:
 4002a8 2f6c6962 36342f6c 642d6c69 6e75782d  /lib64/ld-linux-
 4002b8 7838362d 36342e73 6f2e3200           x86-64.so.2. 
```
/lib64/ld-linux-x86-64.so.2  is the interpreter (runtime linker) to be used (INTERPR headers).
```console
$ objdump -x global | grep INTERP
  INTERP off    0x00000000000002a8 vaddr 0x00000000004002a8 paddr 0x00000000004002a8 align 2**0
```

crtbegin is part of libgcc and is created from crtstuff.c, as is certend actually.
The are passed -DCRT_BEGIN and -DCRT_END respectively as compiler argument.
`crti` is located in glibc/csu (c startup code). 
In Makeconfig we can find:
```
start-installed-name = crt1.o 
```
crt1.o is built from start.c
So we know that our start address is `_start` which has code to setup the
call to `__libc_start_main`.
```c
int __libc_start_main(int *(main) (int, char * *, char * *),
                      int argc,
                      char** ubp_av,
                      void (*init) (void),
                      void (*fini) (void),
                      void (*rtld_fini) (void),
                      void (* stack_end));
```
The fourth argument will be `__libc_csu_init`, for which the source can
be found in elf-init.c. It bascially just calls `_init()`:
```c
void __libc_csu_init (int argc, char **argv, char **envp) { 
#if ELF_INITFINI
  _init ();
#endif

  const size_t size = __init_array_end - __init_array_start;
  for (size_t i = 0; i < size; i++)
    (*__init_array_start [i]) (argc, argv, envp);
}
```
Notice that we are looping over the function pointers and executing them. 
Also, notice these functions accept arguments.

`_init` will be added by the by the linker.
```c
extern void _init (void); 
```


And we can run the executable using:
```console
$ ./global
bajja is running
./global: main...
bajja is ending
```

We can see what the gcc compiler tool chain does by using the `-###` option, 
this will show the commands but not run them:
```
 gcc -### -g -o global global.c
Using built-in specs.
COLLECT_GCC=/usr/bin/gcc
COLLECT_LTO_WRAPPER=/usr/libexec/gcc/x86_64-redhat-linux/9/lto-wrapper
OFFLOAD_TARGET_NAMES=nvptx-none
OFFLOAD_TARGET_DEFAULT=1
Target: x86_64-redhat-linux
Configured with: ../configure --enable-bootstrap --enable-languages=c,c++,fortran,objc,obj-c++,ada,go,d,lto --prefix=/usr --mandir=/usr/share/man --infodir=/usr/share/info --with-bugurl=http://bugzilla.redhat.com/bugzilla --enable-shared --enable-threads=posix --enable-checking=release --enable-multilib --with-system-zlib --enable-__cxa_atexit --disable-libunwind-exceptions --enable-gnu-unique-object --enable-linker-build-id --with-gcc-major-version-only --with-linker-hash-style=gnu --enable-plugin --enable-initfini-array --with-isl --enable-offload-targets=nvptx-none --without-cuda-driver --enable-gnu-indirect-function --enable-cet --with-tune=generic --with-arch_32=i686 --build=x86_64-redhat-linux
Thread model: posix
gcc version 9.2.1 20190827 (Red Hat 9.2.1-1) (GCC) 
COLLECT_GCC_OPTIONS='-g' '-o' 'global' '-mtune=generic' '-march=x86-64'
 /usr/libexec/gcc/x86_64-redhat-linux/9/cc1 -quiet global.c -quiet -dumpbase global.c "-mtune=generic" "-march=x86-64" -auxbase global -g -o /tmp/cc4zbSB5.s
COLLECT_GCC_OPTIONS='-g' '-o' 'global' '-mtune=generic' '-march=x86-64'
 as --64 -o /tmp/cchnVA43.o /tmp/cc4zbSB5.s
COMPILER_PATH=/usr/libexec/gcc/x86_64-redhat-linux/9/:/usr/libexec/gcc/x86_64-redhat-linux/9/:/usr/libexec/gcc/x86_64-redhat-linux/:/usr/lib/gcc/x86_64-redhat-linux/9/:/usr/lib/gcc/x86_64-redhat-linux/
LIBRARY_PATH=/usr/lib/gcc/x86_64-redhat-linux/9/:/usr/lib/gcc/x86_64-redhat-linux/9/../../../../lib64/:/lib/../lib64/:/usr/lib/../lib64/:/usr/lib/gcc/x86_64-redhat-linux/9/../../../:/lib/:/usr/lib/
COLLECT_GCC_OPTIONS='-g' '-o' 'global' '-mtune=generic' '-march=x86-64'
 /usr/libexec/gcc/x86_64-redhat-linux/9/collect2 -plugin /usr/libexec/gcc/x86_64-redhat-linux/9/liblto_plugin.so "-plugin-opt=/usr/libexec/gcc/x86_64-redhat-linux/9/lto-wrapper" "-plugin-opt=-fresolution=/tmp/cc5Np044.res" "-plugin-opt=-pass-through=-lgcc" "-plugin-opt=-pass-through=-lgcc_s" "-plugin-opt=-pass-through=-lc" "-plugin-opt=-pass-through=-lgcc" "-plugin-opt=-pass-through=-lgcc_s" --build-id --no-add-needed --eh-frame-hdr "--hash-style=gnu" -m elf_x86_64 -dynamic-linker /lib64/ld-linux-x86-64.so.2 -o global /usr/lib/gcc/x86_64-redhat-linux/9/../../../../lib64/crt1.o /usr/lib/gcc/x86_64-redhat-linux/9/../../../../lib64/crti.o /usr/lib/gcc/x86_64-redhat-linux/9/crtbegin.o -L/usr/lib/gcc/x86_64-redhat-linux/9 -L/usr/lib/gcc/x86_64-redhat-linux/9/../../../../lib64 -L/lib/../lib64 -L/usr/lib/../lib64 -L/usr/lib/gcc/x86_64-redhat-linux/9/../../.. /tmp/cchnVA43.o -lgcc --push-state --as-needed -lgcc_s --pop-state -lc -lgcc --push-state --as-needed -lgcc_s --pop-state /usr/lib/gcc/x86_64-redhat-linux/9/crtend.o /usr/lib/gcc/x86_64-redhat-linux/9/../../../../lib64/crtn.o
COLLECT_GCC_OPTIONS='-g' '-o' 'global' '-mtune=generic' '-march=x86-64'
```


`~/work/gcc/gcc/libgcc/config/ia64/crtbegin.S`. Note that the capital S indicates
that this file needs to be preprocessed as it contains #include/#define which
have to be processed. A lower case s assembly file is just normal assembly.
So we have to preprocess such fils with `cpp`:

```console
$ cpp hello.S | as -o hello.o -
$ ld -o hello hello.o
$ ./hello
Hello, world!
```

```console
objdump -t globalc -w

globalc:     file format elf64-x86-64

SYMBOL TABLE:
00000000004002a8 l    d  .interp	0000000000000000              .interp
00000000004002c4 l    d  .note.gnu.build-id	0000000000000000              .note.gnu.build-id
00000000004002e8 l    d  .note.ABI-tag	0000000000000000              .note.ABI-tag
0000000000400308 l    d  .gnu.hash	0000000000000000              .gnu.hash
0000000000400328 l    d  .dynsym	0000000000000000              .dynsym
00000000004003a0 l    d  .dynstr	0000000000000000              .dynstr
00000000004003e4 l    d  .gnu.version	0000000000000000              .gnu.version
00000000004003f0 l    d  .gnu.version_r	0000000000000000              .gnu.version_r
0000000000400410 l    d  .rela.dyn	0000000000000000              .rela.dyn
0000000000400440 l    d  .rela.plt	0000000000000000              .rela.plt
0000000000401000 l    d  .init	0000000000000000              .init
0000000000401020 l    d  .plt	0000000000000000              .plt
0000000000401050 l    d  .text	0000000000000000              .text
00000000004011f8 l    d  .fini	0000000000000000              .fini
0000000000402000 l    d  .rodata	0000000000000000              .rodata
0000000000402030 l    d  .eh_frame_hdr	0000000000000000              .eh_frame_hdr
0000000000402078 l    d  .eh_frame	0000000000000000              .eh_frame
0000000000403e08 l    d  .init_array	0000000000000000              .init_array
0000000000403e18 l    d  .fini_array	0000000000000000              .fini_array
0000000000403e20 l    d  .dynamic	0000000000000000              .dynamic
0000000000403ff0 l    d  .got	0000000000000000              .got
0000000000404000 l    d  .got.plt	0000000000000000              .got.plt
0000000000404028 l    d  .data	0000000000000000              .data
000000000040402c l    d  .bss	0000000000000000              .bss
0000000000000000 l    d  .comment	0000000000000000              .comment
0000000000406030 l    d  .gnu.build.attributes	0000000000000000              .gnu.build.attributes
0000000000000000 l    df *ABS*	0000000000000000              /usr/lib/gcc/x86_64-redhat-linux/9/../../../../lib64/crt1.o
000000000040107f l       .text	0000000000000000              .hidden .annobin_init.c
000000000040107f l       .text	0000000000000000              .hidden .annobin_init.c_end
0000000000401050 l       .text	0000000000000000              .hidden .annobin_init.c.hot
0000000000401050 l       .text	0000000000000000              .hidden .annobin_init.c_end.hot
0000000000401050 l       .text	0000000000000000              .hidden .annobin_init.c.unlikely
0000000000401050 l       .text	0000000000000000              .hidden .annobin_init.c_end.unlikely
0000000000401050 l       .text	0000000000000000              .hidden .annobin_init.c.startup
0000000000401050 l       .text	0000000000000000              .hidden .annobin_init.c_end.startup
0000000000401050 l       .text	0000000000000000              .hidden .annobin_init.c.exit
0000000000401050 l       .text	0000000000000000              .hidden .annobin_init.c_end.exit
0000000000401080 l       .text	0000000000000000              .hidden .annobin_static_reloc.c
0000000000401085 l       .text	0000000000000000              .hidden .annobin_static_reloc.c_end
0000000000401050 l       .text	0000000000000000              .hidden .annobin_static_reloc.c.hot
0000000000401050 l       .text	0000000000000000              .hidden .annobin_static_reloc.c_end.hot
0000000000401050 l       .text	0000000000000000              .hidden .annobin_static_reloc.c.unlikely
0000000000401050 l       .text	0000000000000000              .hidden .annobin_static_reloc.c_end.unlikely
0000000000401050 l       .text	0000000000000000              .hidden .annobin_static_reloc.c.startup
0000000000401050 l       .text	0000000000000000              .hidden .annobin_static_reloc.c_end.startup
0000000000401050 l       .text	0000000000000000              .hidden .annobin_static_reloc.c.exit
0000000000401050 l       .text	0000000000000000              .hidden .annobin_static_reloc.c_end.exit
0000000000401080 l       .text	0000000000000000              .hidden .annobin__dl_relocate_static_pie.start
0000000000401085 l       .text	0000000000000000              .hidden .annobin__dl_relocate_static_pie.end
0000000000000000 l    df *ABS*	0000000000000000              crtstuff.c
0000000000401090 l     F .text	0000000000000000              deregister_tm_clones
00000000004010c0 l     F .text	0000000000000000              register_tm_clones
0000000000401100 l     F .text	0000000000000000              __do_global_dtors_aux
000000000040402c l     O .bss	0000000000000001              completed.7392
0000000000403e18 l     O .fini_array	0000000000000000              __do_global_dtors_aux_fini_array_entry
0000000000401130 l     F .text	0000000000000000              frame_dummy
0000000000403e08 l     O .init_array	0000000000000000              __frame_dummy_init_array_entry
0000000000000000 l    df *ABS*	0000000000000000              global.c
0000000000000000 l    df *ABS*	0000000000000000              crtstuff.c
000000000040217c l     O .eh_frame	0000000000000000              __FRAME_END__
0000000000000000 l    df *ABS*	0000000000000000              
0000000000403e18 l       .init_array	0000000000000000              __init_array_end
0000000000403e20 l     O .dynamic	0000000000000000              _DYNAMIC
0000000000403e08 l       .init_array	0000000000000000              __init_array_start
0000000000402030 l       .eh_frame_hdr	0000000000000000              __GNU_EH_FRAME_HDR
0000000000404000 l     O .got.plt	0000000000000000              _GLOBAL_OFFSET_TABLE_
00000000004011f0 g     F .text	0000000000000005              __libc_csu_fini
0000000000404028  w      .data	0000000000000000              data_start
0000000000000000       F *UND*	0000000000000000              puts@@GLIBC_2.2.5
000000000040402c g       .data	0000000000000000              _edata
00000000004011f8 g     F .fini	0000000000000000              .hidden _fini
0000000000000000       F *UND*	0000000000000000              printf@@GLIBC_2.2.5
0000000000000000       F *UND*	0000000000000000              __libc_start_main@@GLIBC_2.2.5
0000000000404028 g       .data	0000000000000000              __data_start
0000000000000000  w      *UND*	0000000000000000              __gmon_start__
0000000000402008 g     O .rodata	0000000000000000              .hidden __dso_handle
0000000000402000 g     O .rodata	0000000000000004              _IO_stdin_used
0000000000401180 g     F .text	0000000000000065              __libc_csu_init
0000000000404030 g       .bss	0000000000000000              _end
0000000000401080 g     F .text	0000000000000005              .hidden _dl_relocate_static_pie
0000000000401050 g     F .text	000000000000002f              _start
000000000040402c g       .bss	0000000000000000              __bss_start
0000000000401147 g     F .text	000000000000002f              main
0000000000404030 g     O .data	0000000000000000              .hidden __TMC_END__
0000000000401136 g     F .text	0000000000000011              bajja
0000000000401000 g     F .init	0000000000000000              .hidden _init
```



### LD Linker Scripts
Remember that the linkers job is to combine object input files into a single
object output file.

Each object file has a list of sections and each section has a name and a size.
If a section is marked `LOAD` it will be loaded into memory when the file is
run. A section can also be marked as `ALLOC` and in this case memory will
be set aside for the section but nothing will be loaded into it. A section that
is not marked as loadable or allocatable most often contains debugging info.

Each of the loadable/allocatable sections have two addresses:
```
1) Virtual Memory Address (VMA)
This is the address the section will have when the output object file is run.

2) Load Memory Address (LMA)
This is the section that the section will be loaded and will most often be the
same as the VMA.
```
```console
$ gcc -c -o sections.o sections.cc 
$ objdump -h sections.o -w

sections.o:     file format elf64-x86-64

Sections:
Idx Name            Size      VMA               LMA               File off  Algn  Flags
  0 .text           00000012  0000000000000000  0000000000000000  00000040  2**0  CONTENTS, ALLOC, LOAD, READONLY, CODE
  1 .data           00000004  0000000000000000  0000000000000000  00000054  2**2  CONTENTS, ALLOC, LOAD, DATA
  2 .bss            00000000  0000000000000000  0000000000000000  00000058  2**0  ALLOC
  3 .comment        0000002d  0000000000000000  0000000000000000  00000058  2**0  CONTENTS, READONLY
  4 .note.GNU-stack 00000000  0000000000000000  0000000000000000  00000085  2**0  CONTENTS, READONLY
  5 .eh_frame       00000038  0000000000000000  0000000000000000  00000088  2**3  CONTENTS, ALLOC, LOAD, RELOC, READONLY, DATA
```


Each object file also has a list of symbols:
```console

sections.o:     file format elf64-x86-64

SYMBOL TABLE:
0000000000000000 l    df *ABS*	          0000000000000000 sections.cc
0000000000000000 l    d  .text	          0000000000000000 .text
0000000000000000 l    d  .data	          0000000000000000 .data
0000000000000000 l    d  .bss	          0000000000000000 .bss
0000000000000000 l    O  .data	          0000000000000004 _ZL5BAJJA
0000000000000000 l    d  .note.GNU-stack  0000000000000000 .note.GNU-stack
0000000000000000 l    d  .eh_frame	  0000000000000000 .eh_frame
0000000000000000 l    d  .comment	  0000000000000000 .comment
0000000000000000 g    F .text             0000000000000012 main
```

Now linker scripts are just text files with commands.

A linker script will always be used, and if one is not specified the default
one will be used. The default linker script can be seen with --verbose:
```console
$ ld --verbose
```

Also, you can specify linker scripts just as you do object files when linking,
and when the linker opens the file and it does not recoginize the file as an
object file or an archive, the linker will try to read it as a linker script.


#### SECTION command
Is used to describe the memory layout of the output file.

```
SECTIONS
{
  . = 0x10000;
  .text : { *(.text) }
  . = 0x8000000;
  .data : { *(.data) }
  .bss : { *(.bss) }
}
```
The dot (`.`) is a special symbol which is the location counter.  If this is not
set it will be get the default value of 0.
Next we have `.text` which starts an output section. Here we are saying that
all .text sections from the input object files should be included into the .text
section of the output object file.

You can list the linker script using:
```console
$ ld --verbose
```
This can be interesting if you want to see what sections are supported for
the current linker as well as the search paths it is using.

### libstdc++
The GNU c++ library implementation can be found in `gcc/libstdc++-v3`.

Lets find out where unique_ptr is declared. This would be inlcude using the
memory header file. `bits/unique_ptr.h` is include from `include/memory` 


### new operator and constructors
When create a new object on the heap using new:
```console
Something* s1 = new Something{5};
```
The new operator will make the compiler produce one function call with the
size of the memory to be allocated.
```console
 401146:	bf 04 00 00 00       	mov    $0x4,%edi
  40114b:	e8 e0 fe ff ff       	callq  401030 <operator new(unsigned long)@plt>
  401150:	48 89 c3             	mov    %rax,%rbx
  401153:	be 05 00 00 00       	mov    $0x5,%esi
  401158:	48 89 df             	mov    %rbx,%rdi
  40115b:	e8 26 00 00 00       	callq  401186 <Something::Something(int)>
  ...

0000000000401186 <Something::Something(int)>:
  401186:	55                   	push   %rbp
  401187:	48 89 e5             	mov    %rsp,%rbp
  40118a:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
  40118e:	89 75 f4             	mov    %esi,-0xc(%rbp)
  401191:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  401195:	8b 55 f4             	mov    -0xc(%rbp),%edx
  401198:	89 10                	mov    %edx,(%rax)
  40119a:	90                   	nop
  40119b:	5d                   	pop    %rbp
  40119c:	c3                   	retq   
  40119d:	0f 1f 00             	nopl   (%rax)
```
Notice that the first argument to Something::Something, in rdi, is the memory
pointer returned by the new operator. The second is 5 which is stored in esi.
The constuctor stores the address as a local variable, and also the 5. It then
moves the pointer to the memory address where our instance type is stored into
rax, and then the local variable 5 into rdx. It then moves edx into the memory
pointed to (dereferenced) by rax.
So this is really all or class instance is in memory.

### constexpr
You can verify that a constexpr is actually performed at compile time using:
```console
$ g++ -c -o constexpr constexpr.cc 
$ objdump -d constexpr

constexpr:     file format elf64-x86-64

Disassembly of section .text:

0000000000000000 <main>:
   0:	55                   	push   %rbp
   1:	48 89 e5             	mov    %rsp,%rbp
   4:	89 7d ec             	mov    %edi,-0x14(%rbp)
   7:	48 89 75 e0          	mov    %rsi,-0x20(%rbp)
   b:	c7 45 fc 05 00 00 00 	movl   $0x5,-0x4(%rbp)
  12:	b8 00 00 00 00       	mov    $0x0,%eax
  17:	5d                   	pop    %rbp
  18:	c3                   	retq   
```



### typename
One this that was not clear to me was that when we have a typename in a
template, for example:
```c++
template <typename T>
struct Something {
  use type = T;
};

SomeType<int>::type v = 18;
```
One can add more types using a separated by a comma: 
```c++
template <typename T, typename U>
struct Something {
  use type = T;
};

SomeType<int, char>::type v = 18;
```
Or we could add more template parameters of a concrete type:
```c++
template <typename T, int I>
struct Something {
  use type = T;
};

SomeType<int, 'c'>::type a = 18;
SomeType<char, 'd'>::type b = 18;
```
Lets take a look at what the compiler generates for:
```console
$ cat type-template-pure.cc 
template<typename T, char C>
struct SomeType {
  using type = T;
};

int main(int argc, char** argv) {
  SomeType<int, 'c'>::type a = 18;
  SomeType<char, 'd'>::type b = 22;

  return 0;
}
```
We can inspect the structs that the compiler generates for the two
instantiations above:
```console
$ clang++ -Xclang -ast-print -fsyntax-only type-template-pure.cc 

template <typename T, char C> struct SomeType {
    using type = T;
};

template<> struct SomeType<int, 'c'> {
    using type = int;
};

template<> struct SomeType<char, 'd'> {
    using type = char;
};

int main(int argc, char **argv) {
    SomeType<int, 'c'>::type a = 18;
    SomeType<char, 'd'>::type b = 22;
    return 0;
}
```
Lets take a look at what a type template compiles down to.
```console
$ g++ -g -o type-template-pure type-template-pure.cc
$ objdump -dC type-template-pure
```

One way to look at the expression:
```c++
    SomeType<int, 'c'>::type a = 18;
```
Is to think of SometType as a function:
```c++
    SomeType(int, 'c')::return_value a = 18;
```
SO we have a function name, which is the name of the struct, and it takes
arguments which are the template parameters and the we have :: followed by the
return value.


### typenum
target/debug/build/typenum-1e3c22f3e18bf64a/out/consts.rs
```rust
pub mod consts {
  use crate::uint::{UInt, UTerm};                                             
  use crate::int::{PInt, NInt};
  pub type True = B1;                                                         
  pub type False = B0;                                                        
  pub type U0 = UTerm;
  ...
  pub type U4 = UInt<UInt<UInt<UTerm, B1>, B0>, B0>; 
  pub type N4 = NInt<U4>;  
```
Lets start by taking a look at Uint (src/uint.rs):
```rust
pub struct UInt<U, B> {                                                         
    /// The more significant bits of `Self`.                                    
    pub(crate) msb: U,                                                          
    /// The least significant bit of `Self`.                                    
    pub(crate) lsb: B,                                                          
}
```
Notice that UInt takes two type parameters which was not obvious when I looked
at this the first time. But we can separate these:
```rust
                   U     U    U     B    B      B 
pub type U4 = UInt<UInt<UInt<UTerm, B1>, B0>, B0>; 
                              0     1    0    0

pub type U3 = UInt<UInt<UTerm, B1>, B1>;
                         0     1     1

pub type U2 = UInt<UInt<UTerm, B1>, B0>;
                          0    1     0
```

###  stringop-truncation
```
The -Wstringop-truncation warning added in GCC 8.0 via r254630 for bug 81117 is
specifically intended to highlight likely unintended uses of the strncpy
function that truncate the terminating NUL charcter from the source string.
```
gt

Note that we have to compile with optimizations to produce this warning:
```console
$ gcc -Wall -O3 -o stringop-trunaction stringop-truncation.cc 
stringop-truncation.cc: In function ‘int main(int, char**)’:
stringop-truncation.cc:22:10: warning: ‘char* strncpy(char*, const char*, size_t)’ output truncated before terminating nul copying 5 bytes from a string of the same length [-Wstringop-truncation]
   22 |   strncpy(id, _id, len);
      |   ~~~~~~~^~~~~~~~~~~~~~
```
In the example [stringop-truncation.cc](src/fundamentals/stringop-truncation.cc)
we are using strlen to get the length of a string which does not include the
null-terminator. This length is then used with strncpy which will copy into the
destination, the characters from source but only upto the length. So is the
intention was to preserve the null-terminator then this warning makes us aware
of this. So this may be what the user intended or not. If this is intenational
then we can ignore the warning using a pragma:
```c
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wstringop-truncation"
  ...
#pragma GCC diagnostic pop

```

```console
cstring.h:43:70: warning: ‘char* strncpy(char*, const char*, size_t)’ output truncated before terminating nul copying as many bytes from a string as its length [-Wstringop-truncation]
   43 | #define uprv_strncpy(dst, src, size) U_STANDARD_CPP_NAMESPACE strncpy(dst, src, size)
ucurr.cpp:385:9: note: in expansion of macro ‘uprv_strncpy’
  385 |         uprv_strncpy(id, _id, len);
      |         ^~~~~~~~~~~~
ucurr.cpp: In function ‘const void* ucurr_register_70(const UChar*, const char*, UErrorCode*)’:
cstring.h:37:57: note: length computed here
   37 | #define uprv_strlen(str) U_STANDARD_CPP_NAMESPACE strlen(str)
ucurr.cpp:381:32: note: in expansion of macro ‘uprv_strlen’
  381 |         int32_t len = (int32_t)uprv_strlen(_id);
      |                                ^~~~~~~~~~~
```
The warning originates from:
```c
/**                                                                             
 * Useful constant for the maximum size of the whole locale ID                  
 * (including the terminating NULL and all keywords).                           
 * @stable ICU 2.0                                                              
 */                                                                             
#define ULOC_FULLNAME_CAPACITY 157 

struct CReg : public icu::UMemory {
    CReg *next;
    UChar iso[ISO_CURRENCY_CODE_LENGTH+1];
    char  id[ULOC_FULLNAME_CAPACITY];

    CReg(const UChar* _iso, const char* _id) : next(0) {                                                                           
        int32_t len = (int32_t)uprv_strlen(_id);
        if (len > (int32_t)(sizeof(id)-1)) {
            len = (sizeof(id)-1);
        }
        uprv_strncpy(id, _id, len);
        id[len] = 0;
        u_memcpy(iso, _iso, ISO_CURRENCY_CODE_LENGTH);
        iso[ISO_CURRENCY_CODE_LENGTH] = 0;
    }
```
`upvr_strncpy` 
