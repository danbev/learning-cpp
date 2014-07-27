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

# Declare libraries and define tests here...


# Define programs run automatically by "make check"
TESTS = $(check_PROGRAMS)
