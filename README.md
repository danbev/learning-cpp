## Learning C++11 
The sole purpose of this project is to learn C++11 and techniques around setting up a project for C++11. 


### Building
This project uses Autotool and is required to bulid

    autoreconf --install
    ./configure
    make

The produces programs are in in the same folder, _src_, as the source files.

#### Manually compiling a program
Compiling with c++11 and libc:
clang++ -std=c++11 -stdlib=libc++ types.cpp -o types

### Running tests

