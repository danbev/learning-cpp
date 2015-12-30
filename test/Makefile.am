# Define programs built by "make check" but not necessarily run
check_PROGRAMS = 

# Declare libraries to test
libsearch = $(top_builddir)/src/libsearch.la

check_PROGRAMS += bubblesort_test
bubblesort_test_SOURCES = bubblesort_test.cpp bubblesort.hpp
bubblesort_test_CPPFLAGS = -I$(top_srcdir)/src/algorithms/sorting $(GTEST_CPPFLAGS)
bubblesort_test_CXXFLAGS = $(GTEST_CXXFLAGS)
bubblesort_test_LDFLAGS = $(GTEST_LDFLAGS)
bubblesort_test_LDADD = $(libsearch) $(GTEST_LIBS) $(top_builddir)/src/algorithms/sorting/bubblesort.o -lgtest_main

check_PROGRAMS += selectionsort_test
selectionsort_test_SOURCES = selectionsort_test.cpp selectionsort.hpp
selectionsort_test_CPPFLAGS = -I$(top_srcdir)/src/ $(GTEST_CPPFLAGS)
selectionsort_test_CXXFLAGS = $(GTEST_CXXFLAGS)
selectionsort_test_LDFLAGS = $(GTEST_LDFLAGS)
selectionsort_test_LDADD = $(libsearch) $(GTEST_LIBS) $(top_builddir)/src/selectionsort.o -lgtest_main

check_PROGRAMS += insertionsort_test
insertionsort_test_SOURCES = insertionsort_test.cpp insertionsort.hpp
insertionsort_test_CPPFLAGS = -I$(top_srcdir)/src/algorithms/sorting $(GTEST_CPPFLAGS)
insertionsort_test_CXXFLAGS = $(GTEST_CXXFLAGS)
insertionsort_test_LDFLAGS = $(GTEST_LDFLAGS)
insertionsort_test_LDADD = $(libsearch) $(GTEST_LIBS) $(top_builddir)/src/algorithms/sorting/insertionsort.o -lgtest_main

check_PROGRAMS += shellsort_test
shellsort_test_SOURCES = shellsort_test.cpp shellsort.hpp
shellsort_test_CPPFLAGS = -I$(top_srcdir)/src/ $(GTEST_CPPFLAGS)
shellsort_test_CXXFLAGS = $(GTEST_CXXFLAGS)
shellsort_test_LDFLAGS = $(GTEST_LDFLAGS)
shellsort_test_LDADD = $(libsearch) $(GTEST_LIBS) $(top_builddir)/src/shellsort.o -lgtest_main

#check_PROGRAMS += quicksort_test
#quicksort_test_SOURCES = quicksort_test.cpp quicksort.hpp
#quicksort_test_CPPFLAGS = -I$(top_srcdir)/src/algorithms/sorting $(GTEST_CPPFLAGS)
#quicksort_test_CXXFLAGS = $(GTEST_CXXFLAGS)
#quicksort_test_LDFLAGS = $(GTEST_LDFLAGS)
#quicksort_test_LDADD = $(libsearch) $(GTEST_LIBS) $(top_builddir)/src/algorithms/sorting/quicksort.o -lgtest_main

check_PROGRAMS += mergesort_test
mergesort_test_SOURCES = mergesort_test.cpp mergesort.hpp
mergesort_test_CPPFLAGS = -I$(top_srcdir)/src/algorithms/sorting $(GTEST_CPPFLAGS)
mergesort_test_CXXFLAGS = $(GTEST_CXXFLAGS)
mergesort_test_LDFLAGS = $(GTEST_LDFLAGS)
mergesort_test_LDADD = $(libsearch) $(GTEST_LIBS) $(top_builddir)/src/algorithms/sorting/mergesort.o -lgtest_main

check_PROGRAMS += recursive_test
recursive_test_SOURCES = recursive_test.cpp 
recursive_test_CPPFLAGS = -I$(top_srcdir)/src/ $(GTEST_CPPFLAGS)
recursive_test_CXXFLAGS = $(GTEST_CXXFLAGS)
recursive_test_LDFLAGS = $(GTEST_LDFLAGS)
recursive_test_LDADD = $(libsearch) $(GTEST_LIBS) -lgtest_main

check_PROGRAMS += search_test
search_test_SOURCES = search_test.cpp 
search_test_CPPFLAGS = -I$(top_srcdir)/src/ $(GTEST_CPPFLAGS)
search_test_CXXFLAGS = $(GTEST_CXXFLAGS)
search_test_LDFLAGS = $(GTEST_LDFLAGS)
search_test_LDADD = $(libsearch) $(GTEST_LIBS) -lgtest_main

check_PROGRAMS += quickunion_test
quickunion_test_SOURCES = ./algorithms/fundamentals/quickunion_test.cpp
quickunion_test_CPPFLAGS = -I$(top_srcdir)/src/algorithms/fundamental $(GTEST_CPPFLAGS)
quickunion_test_CXXFLAGS = $(GTEST_CXXFLAGS)
quickunion_test_LDFLAGS = $(GTEST_LDFLAGS)
quickunion_test_LDADD = $(libsearch) $(GTEST_LIBS) -lgtest_main

check_PROGRAMS += quickfind_test
quickfind_test_SOURCES = ./algorithms/fundamentals/quickfind_test.cpp
quickfind_test_CPPFLAGS = -I$(top_srcdir)/src/algorithms/fundamental $(GTEST_CPPFLAGS)
quickfind_test_CXXFLAGS = $(GTEST_CXXFLAGS)
quickfind_test_LDFLAGS = $(GTEST_LDFLAGS)
quickfind_test_LDADD = $(libsearch) $(GTEST_LIBS) -lgtest_main

# Declare libraries and define tests here...

# Define programs run automatically by "make check"
TESTS = $(check_PROGRAMS)
