bin_PROGRAMS = types pointer shellsort
types_SOURCES = types.cpp
pointer_SOURCES = pointer.cpp
shellsort_SOURCES = shellsort.hpp shellsort.cpp
CXX=clang++
CXXFLAGS="-g" 
LDFLAGS="-g"
AM_CFLAGS ="-g"
AM_CXXFLAGS="-std=c++0x"
nobase_pkginclude_HEADERS = search.hpp recursive.hpp
lib_LTLIBRARIES = libsearch.la
libsearch_la_SOURCES = search.hpp search.cpp recursive.hpp recursive.cpp
