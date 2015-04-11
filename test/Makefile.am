# Define programs built by "make check" but not necessarily run
check_PROGRAMS = 

# Declare libraries to test
libsearch = $(top_builddir)/src/libsearch.la

# Define tests with gtest
check_PROGRAMS += search_test
search_test_SOURCES = search_test.cpp 
search_test_CPPFLAGS = -I$(top_srcdir)/src/ $(GTEST_CPPFLAGS)
search_test_CXXFLAGS = $(GTEST_CXXFLAGS)
search_test_LDFLAGS = $(GTEST_LDFLAGS)
search_test_LDADD = $(libsearch) $(GTEST_LIBS) -lgtest_main

check_PROGRAMS += sort_test
sort_test_SOURCES = sort_test.cpp 
sort_test_CPPFLAGS = -I$(top_srcdir)/src/ $(GTEST_CPPFLAGS)
sort_test_CXXFLAGS = $(GTEST_CXXFLAGS)
sort_test_LDFLAGS = $(GTEST_LDFLAGS)
sort_test_LDADD = $(libsearch) $(GTEST_LIBS) -lgtest_main

check_PROGRAMS += recursive_test
recursive_test_SOURCES = recursive_test.cpp 
recursive_test_CPPFLAGS = -I$(top_srcdir)/src/ $(GTEST_CPPFLAGS)
recursive_test_CXXFLAGS = $(GTEST_CXXFLAGS)
recursive_test_LDFLAGS = $(GTEST_LDFLAGS)
recursive_test_LDADD = $(libsearch) $(GTEST_LIBS) -lgtest_main

check_PROGRAMS += shellsort_test
shellsort_test_SOURCES = shellsort_test.cpp shellsort.hpp
shellsort_test_CPPFLAGS = -I$(top_srcdir)/src/ $(GTEST_CPPFLAGS)
shellsort_test_CXXFLAGS = $(GTEST_CXXFLAGS)
shellsort_test_LDFLAGS = $(GTEST_LDFLAGS)
shellsort_test_LDADD = $(libsearch) $(GTEST_LIBS) $(top_builddir)/src/shellsort.o -lgtest_main

# Declare libraries and define tests here...

# Define programs run automatically by "make check"
TESTS = $(check_PROGRAMS)
