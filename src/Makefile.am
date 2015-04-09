bin_PROGRAMS = types bs pointer
types_SOURCES = types.cpp
bs_SOURCES = bs.cpp
pointer_SOURCES = pointer.cpp
AM_CXXFLAGS="-std=c++0x -g -DDEBUG"

nobase_pkginclude_HEADERS = search.hpp sort.hpp recursive.hpp
lib_LTLIBRARIES = libsearch.la
libsearch_la_SOURCES = search.hpp search.cpp sort.hpp sort.cpp recursive.hpp recursive.cpp
