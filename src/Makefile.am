bin_PROGRAMS = types bs pointer shellsort mergesort selectionsort
types_SOURCES = types.cpp
bs_SOURCES = bs.cpp
pointer_SOURCES = pointer.cpp
shellsort_SOURCES = shellsort.hpp shellsort.cpp
mergesort_SOURCES = mergesort.hpp mergesort.cpp
selectionsort_SOURCES = selectionsort.hpp selectionsort.cpp
CFLAGS="-g" 
CXXFLAGS="-g" 
LDFLAGS="-g"
AM_CFLAGS ="-g"
AM_CXXFLAGS="-std=c++0x"
nobase_pkginclude_HEADERS = search.hpp sort.hpp recursive.hpp
lib_LTLIBRARIES = libsearch.la
libsearch_la_SOURCES = search.hpp search.cpp sort.hpp sort.cpp recursive.hpp recursive.cpp
