bin_PROGRAMS = types bs pointer shellsort mergesort selectionsort insertionsort bubblesort quicksort
types_SOURCES = types.cpp
bs_SOURCES = bs.cpp
pointer_SOURCES = pointer.cpp
shellsort_SOURCES = shellsort.hpp shellsort.cpp
mergesort_SOURCES = mergesort.hpp mergesort.cpp
selectionsort_SOURCES = selectionsort.hpp selectionsort.cpp
insertionsort_SOURCES = insertionsort.hpp insertionsort.cpp
bubblesort_SOURCES = bubblesort.hpp bubblesort.cpp
quicksort_SOURCES = quicksort_header.hpp quicksort.cpp
CXX=clang++
#CFLAGS="-g -mmacosx-version-min=10.6" 
CXXFLAGS="-g" 
LDFLAGS="-g"
AM_CFLAGS ="-g"
AM_CXXFLAGS="-std=c++0x"
nobase_pkginclude_HEADERS = search.hpp recursive.hpp
lib_LTLIBRARIES = libsearch.la
libsearch_la_SOURCES = search.hpp search.cpp recursive.hpp recursive.cpp
