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
`N` is nested inside a scope of a namespace or a class
`9Something` this is length of the function name followed by the function name. 
`C1` complete object constructor
`C2` base object constructor
`E` end nested (namespace or class).
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



## const
There is a [const_test.cc](./test/fundamentals/const_test.cc) for referense regarding using const. 

const can go before or after after the type:

    const T t;
    T const t;

The above are the same as it the following example with int data type:

    int const number = 10;
    const int number = 10;

One thing to not is when using const with pointers and where you put the const. This determines if you want the pointer to be const of the things the pointer is pointing to to be const.

Pointer to const:

    int const *number;
    const int *number;

Here the pointer is not const but what it points to is (int const).

Const pointer to variable you have to put const after the *:

    int* const number;
   

### Strings
A std::string usually stores a pointer to a location on the heap. It also needs to store the size of the data, and the capacity.
So: 
size = the length of the string.
capacity = how many chars the string can hold before it has to allocate a new, larger buffer from the heap.
data = pointer to the char array.

Some implementations allow for storing strings as local variables on the stack (not too large though as that might overflow the stack). 
This is called Small String Optimization.
In this case there would be a char[20] for example.

Lets take a look at the following string:

    #include <string>
    ...
    std::string s{"bajja"};

What does the compiler interpret this as?
What is std::string actually?
I believe it is a template in /usr/include/c++/4.2.1/bits/stringfwd.h:

    typedef basic_string<char> string;

And what then is basic_string? :

    template<typename _CharT, typename _Traits = char_traits<_CharT>,
             typename _Alloc = allocator<_CharT> >
      class basic_string;

    template<> struct char_traits<char>;
    template<class _CharT> struct char_traits;
    template<typename _Alloc> class allocator;

If we now run nm this (see [string-type.cc](./src/fundamentals/string-type.cc) we find:

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


### Inline namespaces

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
One thing to not is that new does not only allocate memory, it also calls the constructor. And same with delete, it will
not only reclaim the memory but will first call the destructor.

### Type traits
Were introduced with TR1 and extended with C++11 and provide a way to define behaviour depending
on types.

A type trait is a templated struct and its member variables give you information about 
the type it the type template is templated on.

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
true and a type.
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
