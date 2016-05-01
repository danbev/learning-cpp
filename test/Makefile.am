# Define programs built by "make check" but not necessarily run
check_PROGRAMS = 

check_PROGRAMS += bubblesort_test
bubblesort_test_SOURCES = ./algorithms/sorting/bubblesort_test.cpp bubblesort.hpp
bubblesort_test_CPPFLAGS = -I$(top_srcdir)/src/algorithms/sorting $(GTEST_CPPFLAGS)
bubblesort_test_CXXFLAGS = $(GTEST_CXXFLAGS)
bubblesort_test_LDFLAGS = $(GTEST_LDFLAGS)
bubblesort_test_LDADD = $(GTEST_LIBS) $(top_builddir)/src/algorithms/sorting/bubblesort.o -lgtest_main

check_PROGRAMS += selectionsort_test
selectionsort_test_SOURCES = ./algorithms/sorting/selectionsort_test.cpp selectionsort.hpp
selectionsort_test_CPPFLAGS = -I$(top_srcdir)/src/algorithms/sorting $(GTEST_CPPFLAGS)
selectionsort_test_CXXFLAGS = $(GTEST_CXXFLAGS)
selectionsort_test_LDFLAGS = $(GTEST_LDFLAGS)
selectionsort_test_LDADD = $(GTEST_LIBS) $(top_builddir)/src/algorithms/sorting/selectionsort.o -lgtest_main

check_PROGRAMS += insertionsort_test
insertionsort_test_SOURCES = ./algorithms/sorting/insertionsort_test.cpp insertionsort.hpp
insertionsort_test_CPPFLAGS = -I$(top_srcdir)/src/algorithms/sorting $(GTEST_CPPFLAGS)
insertionsort_test_CXXFLAGS = $(GTEST_CXXFLAGS)
insertionsort_test_LDFLAGS = $(GTEST_LDFLAGS)
insertionsort_test_LDADD = $(GTEST_LIBS) $(top_builddir)/src/algorithms/sorting/insertionsort.o -lgtest_main

check_PROGRAMS += shellsort_test
shellsort_test_SOURCES = ./algorithms/sorting/shellsort_test.cpp shellsort.hpp
shellsort_test_CPPFLAGS = -I$(top_srcdir)/src/algorithms/sorting $(GTEST_CPPFLAGS)
shellsort_test_CXXFLAGS = $(GTEST_CXXFLAGS)
shellsort_test_LDFLAGS = $(GTEST_LDFLAGS)
shellsort_test_LDADD = $(GTEST_LIBS) $(top_builddir)/src/algorithms/sorting/shellsort.o -lgtest_main

check_PROGRAMS += quicksort_test
quicksort_test_SOURCES = ./algorithms/sorting/quicksort_test.cpp
quicksort_test_CPPFLAGS = -I$(top_srcdir)/src/algorithms/sorting $(GTEST_CPPFLAGS)
quicksort_test_CXXFLAGS = $(GTEST_CXXFLAGS)
quicksort_test_LDFLAGS = $(GTEST_LDFLAGS)
#quicksort_test_LDADD = $(GTEST_LIBS) $(top_builddir)/src/algorithms/sorting/quicksort.o -lgtest_main
quicksort_test_LDADD = $(GTEST_LIBS) -lgtest_main

check_PROGRAMS += mergesort_test
mergesort_test_SOURCES = ./algorithms/sorting/mergesort_test.cpp mergesort.hpp
mergesort_test_CPPFLAGS = -I$(top_srcdir)/src/algorithms/sorting $(GTEST_CPPFLAGS)
mergesort_test_CXXFLAGS = $(GTEST_CXXFLAGS)
mergesort_test_LDFLAGS = $(GTEST_LDFLAGS)
mergesort_test_LDADD = $(GTEST_LIBS) $(top_builddir)/src/algorithms/sorting/mergesort.o -lgtest_main

check_PROGRAMS += bu_mergesort_test
bu_mergesort_test_SOURCES = ./algorithms/sorting/bu_mergesort_test.cpp
bu_mergesort_test_CPPFLAGS = -I$(top_srcdir)/src/algorithms/sorting $(GTEST_CPPFLAGS)
bu_mergesort_test_CXXFLAGS = $(GTEST_CXXFLAGS)
bu_mergesort_test_LDFLAGS = $(GTEST_LDFLAGS)
bu_mergesort_test_LDADD = $(GTEST_LIBS) -lgtest_main

check_PROGRAMS += recursive_test
recursive_test_SOURCES = ./algorithms/recursive/recursive_test.cpp 
recursive_test_CPPFLAGS = -I$(top_srcdir)/src/algorithms/recursive $(GTEST_CPPFLAGS)
recursive_test_CXXFLAGS = $(GTEST_CXXFLAGS)
recursive_test_LDFLAGS = $(GTEST_LDFLAGS)
recursive_test_LDADD = $(GTEST_LIBS) -lgtest_main

check_PROGRAMS += quickunion_test
quickunion_test_SOURCES = ./algorithms/fundamentals/quickunion_test.cpp
quickunion_test_CPPFLAGS = -I$(top_srcdir)/src/algorithms/fundamental $(GTEST_CPPFLAGS)
quickunion_test_CXXFLAGS = $(GTEST_CXXFLAGS)
quickunion_test_LDFLAGS = $(GTEST_LDFLAGS)
quickunion_test_LDADD = $(GTEST_LIBS) -lgtest_main

check_PROGRAMS += quickfind_test
quickfind_test_SOURCES = ./algorithms/fundamentals/quickfind_test.cpp
quickfind_test_CPPFLAGS = -I$(top_srcdir)/src/algorithms/fundamental $(GTEST_CPPFLAGS)
quickfind_test_CXXFLAGS = $(GTEST_CXXFLAGS)
quickfind_test_LDFLAGS = $(GTEST_LDFLAGS)
quickfind_test_LDADD = $(GTEST_LIBS) -lgtest_main

check_PROGRAMS += randomize_test
randomize_test_SOURCES = ./algorithms/fundamentals/randomize_test.cpp
randomize_test_CPPFLAGS = -I$(top_srcdir)/src/algorithms/fundamental $(GTEST_CPPFLAGS)
randomize_test_CXXFLAGS = $(GTEST_CXXFLAGS)
randomize_test_LDFLAGS = $(GTEST_LDFLAGS)
randomize_test_LDADD = $(GTEST_LIBS) -lgtest_main

check_PROGRAMS += gcd_test
gcd_test_SOURCES = ./algorithms/fundamentals/gcd_test.cpp
gcd_test_CPPFLAGS = -I$(top_srcdir)/src/algorithms/fundamental $(GTEST_CPPFLAGS)
gcd_test_CXXFLAGS = $(GTEST_CXXFLAGS)
gcd_test_LDFLAGS = $(GTEST_LDFLAGS)
gcd_test_LDADD = $(GTEST_LIBS) -lgtest_main

check_PROGRAMS += lcg_test
lcg_test_SOURCES = ./algorithms/fundamentals/lcg_test.cpp
lcg_test_CPPFLAGS = -I$(top_srcdir)/src/algorithms/fundamental $(GTEST_CPPFLAGS)
lcg_test_CXXFLAGS = $(GTEST_CXXFLAGS)
lcg_test_LDFLAGS = $(GTEST_LDFLAGS)
lcg_test_LDADD = $(GTEST_LIBS) -lgtest_main

check_PROGRAMS += triangular_array_test
triangular_array_test_SOURCES = ./algorithms/fundamentals/triangular_array_test.cpp
triangular_array_test_CPPFLAGS = -I$(top_srcdir)/src/algorithms/fundamental $(GTEST_CPPFLAGS)
triangular_array_test_CXXFLAGS = $(GTEST_CXXFLAGS)
triangular_array_test_LDFLAGS = $(GTEST_LDFLAGS)
triangular_array_test_LDADD = $(GTEST_LIBS) -lgtest_main

check_PROGRAMS += linkedlist_test
linkedlist_test_SOURCES = ./algorithms/datastructures/linkedlist_test.cpp
linkedlist_test_CPPFLAGS = -I$(top_srcdir)/src/algorithms/datastructures $(GTEST_CPPFLAGS)
linkedlist_test_CXXFLAGS = $(GTEST_CXXFLAGS)
linkedlist_test_LDFLAGS = $(GTEST_LDFLAGS)
linkedlist_test_LDADD = $(GTEST_LIBS) -lgtest_main

check_PROGRAMS += dlinkedlist_test
dlinkedlist_test_SOURCES = ./algorithms/datastructures/dlinkedlist_test.cpp
dlinkedlist_test_CPPFLAGS = -I$(top_srcdir)/src/algorithms/datastructures $(GTEST_CPPFLAGS)
dlinkedlist_test_CXXFLAGS = $(GTEST_CXXFLAGS)
dlinkedlist_test_LDFLAGS = $(GTEST_LDFLAGS)
dlinkedlist_test_LDADD = $(GTEST_LIBS) -lgtest_main

check_PROGRAMS += primenumbers_test
primenumbers_test_SOURCES = ./algorithms/fundamentals/primenumbers_test.cpp
primenumbers_test_CPPFLAGS = -I$(top_srcdir)/src/algorithms/fundamental $(GTEST_CPPFLAGS)
primenumbers_test_CXXFLAGS = $(GTEST_CXXFLAGS)
primenumbers_test_LDFLAGS = $(GTEST_LDFLAGS)
primenumbers_test_LDADD = $(GTEST_LIBS) -lgtest_main

check_PROGRAMS += pattern_test
pattern_test_SOURCES = ./algorithms/searching/pattern_test.cpp
pattern_test_CPPFLAGS = -I$(top_srcdir)/src/algorithms/searching $(GTEST_CPPFLAGS)
pattern_test_CXXFLAGS = $(GTEST_CXXFLAGS)
pattern_test_LDFLAGS = $(GTEST_LDFLAGS)
pattern_test_LDADD = $(GTEST_LIBS) -lgtest_main

check_PROGRAMS += binaryheap_test
binaryheap_test_SOURCES = ./algorithms/datastructures/binaryheap_test.cpp
binaryheap_test_CPPFLAGS = -I$(top_srcdir)/src/algorithms/datastructures $(GTEST_CPPFLAGS)
binaryheap_test_CXXFLAGS = $(GTEST_CXXFLAGS)
binaryheap_test_LDFLAGS = $(GTEST_LDFLAGS)
binaryheap_test_LDADD = $(GTEST_LIBS) -lgtest_main

check_PROGRAMS += heapsort_test
heapsort_test_SOURCES = ./algorithms/datastructures/heapsort_test.cpp
heapsort_test_CPPFLAGS = -I$(top_srcdir)/src/algorithms/datastructures $(GTEST_CPPFLAGS)
heapsort_test_CXXFLAGS = $(GTEST_CXXFLAGS)
heapsort_test_LDFLAGS = $(GTEST_LDFLAGS)
heapsort_test_LDADD = $(GTEST_LIBS) -lgtest_main

check_PROGRAMS += bst_test
bst_test_SOURCES = ./algorithms/datastructures/bst_test.cpp
bst_test_CPPFLAGS = -I$(top_srcdir)/src/algorithms/datastructures $(GTEST_CPPFLAGS)
bst_test_CXXFLAGS = $(GTEST_CXXFLAGS)
bst_test_LDFLAGS = $(GTEST_LDFLAGS)
bst_test_LDADD = $(GTEST_LIBS) -lgtest_main

check_PROGRAMS += modulo_bias_test
modulo_bias_test_SOURCES = ./algorithms/fundamentals/modulo_bias_test.cpp
modulo_bias_test_CPPFLAGS = -I$(top_srcdir)/src/algorithms/fundamental $(GTEST_CPPFLAGS)
modulo_bias_test_CXXFLAGS = $(GTEST_CXXFLAGS)
modulo_bias_test_LDFLAGS = $(GTEST_LDFLAGS)
modulo_bias_test_LDADD = $(GTEST_LIBS) -lgtest_main

check_PROGRAMS += sequential_symbol_table_test
sequential_symbol_table_test_SOURCES = ./algorithms/datastructures/sequential_symbol_table_test.cpp
sequential_symbol_table_test_CPPFLAGS = -I$(top_srcdir)/src/algorithms/datastructures $(GTEST_CPPFLAGS)
sequential_symbol_table_test_CXXFLAGS = $(GTEST_CXXFLAGS)
sequential_symbol_table_test_LDFLAGS = $(GTEST_LDFLAGS)
sequential_symbol_table_test_LDADD = $(GTEST_LIBS) -lgtest_main

check_PROGRAMS += binary_search_symbol_table_test
binary_search_symbol_table_test_SOURCES = ./algorithms/datastructures/binary_search_symbol_table_test.cpp
binary_search_symbol_table_test_CPPFLAGS = -I$(top_srcdir)/src/algorithms/datastructures $(GTEST_CPPFLAGS) 
binary_search_symbol_table_test_CXXFLAGS = $(GTEST_CXXFLAGS) 
binary_search_symbol_table_test_LDFLAGS = $(GTEST_LDFLAGS)
binary_search_symbol_table_test_LDADD = $(GTEST_LIBS) -lgtest_main

check_PROGRAMS += red_black_bst_test
red_black_bst_test_SOURCES = ./algorithms/datastructures/red_black_bst_test.cpp
red_black_bst_test_CPPFLAGS = -I$(top_srcdir)/src/algorithms/datastructures $(GTEST_CPPFLAGS) 
red_black_bst_test_CXXFLAGS = $(GTEST_CXXFLAGS) 
red_black_bst_test_LDFLAGS = $(GTEST_LDFLAGS)
red_black_bst_test_LDADD = $(GTEST_LIBS) -lgtest_main

check_PROGRAMS += hash_table_chaining_test
hash_table_chaining_test_SOURCES = ./algorithms/datastructures/hash_table_chaining_test.cpp
hash_table_chaining_test_CPPFLAGS = -I$(top_srcdir)/src/algorithms/datastructures $(GTEST_CPPFLAGS) 
hash_table_chaining_test_CXXFLAGS = $(GTEST_CXXFLAGS) 
hash_table_chaining_test_LDFLAGS = $(GTEST_LDFLAGS)
hash_table_chaining_test_LDADD = $(GTEST_LIBS) -lgtest_main

check_PROGRAMS += binary_search_test
binary_search_test_SOURCES = ./algorithms/searching/binary_search_test.cpp
binary_search_test_CPPFLAGS = -I$(top_srcdir)/src/algorithms/searching $(GTEST_CPPFLAGS) 
binary_search_test_CXXFLAGS = $(GTEST_CXXFLAGS) 
binary_search_test_LDFLAGS = $(GTEST_LDFLAGS)
binary_search_test_LDADD = $(GTEST_LIBS) -lgtest_main

check_PROGRAMS += stack_test
stack_test_SOURCES = ./algorithms/datastructures/stack_test.cpp
stack_test_CPPFLAGS = -I$(top_srcdir)/src/algorithms/datastructures $(GTEST_CPPFLAGS) 
stack_test_CXXFLAGS = $(GTEST_CXXFLAGS) 
stack_test_LDFLAGS = $(GTEST_LDFLAGS)
stack_test_LDADD = $(GTEST_LIBS) -lgtest_main

check_PROGRAMS += hash_table_linear_probing_test
hash_table_linear_probing_test_SOURCES = ./algorithms/datastructures/hash_table_linear_probing_test.cpp
hash_table_linear_probing_test_CPPFLAGS = -I$(top_srcdir)/src/algorithms/datastructures $(GTEST_CPPFLAGS) 
hash_table_linear_probing_test_CXXFLAGS = $(GTEST_CXXFLAGS) 
hash_table_linear_probing_test_LDFLAGS = $(GTEST_LDFLAGS)
hash_table_linear_probing_test_LDADD = $(GTEST_LIBS) -lgtest_main

check_PROGRAMS += undirected_graph_test
undirected_graph_test_SOURCES = ./algorithms/graphs/undirected_graph_test.cpp
undirected_graph_test_CPPFLAGS = -I$(top_srcdir)/src/algorithms/graphs $(GTEST_CPPFLAGS) 
undirected_graph_test_CXXFLAGS = $(GTEST_CXXFLAGS) 
undirected_graph_test_LDFLAGS = $(GTEST_LDFLAGS)
undirected_graph_test_LDADD = $(GTEST_LIBS) -lgtest_main

check_PROGRAMS += bag_test
bag_test_SOURCES = ./algorithms/datastructures/bag_test.cpp
bag_test_CPPFLAGS = -I$(top_srcdir)/src/algorithms/datastructures $(GTEST_CPPFLAGS) 
bag_test_CXXFLAGS = $(GTEST_CXXFLAGS) 
bag_test_LDFLAGS = $(GTEST_LDFLAGS)
bag_test_LDADD = $(GTEST_LIBS) -lgtest_main

check_PROGRAMS += search_test
search_test_SOURCES = ./algorithms/graphs/search_test.cpp
search_test_CPPFLAGS = -I$(top_srcdir)/src/algorithms/graphs $(GTEST_CPPFLAGS) 
search_test_CXXFLAGS = $(GTEST_CXXFLAGS) 
search_test_LDFLAGS = $(GTEST_LDFLAGS)
search_test_LDADD = $(GTEST_LIBS) -lgtest_main

check_PROGRAMS += depth_first_search_test
depth_first_search_test_SOURCES = ./algorithms/graphs/depth_first_search_test.cpp
depth_first_search_test_CPPFLAGS = -I$(top_srcdir)/src/algorithms/graphs $(GTEST_CPPFLAGS) 
depth_first_search_test_CXXFLAGS = $(GTEST_CXXFLAGS) 
depth_first_search_test_LDFLAGS = $(GTEST_LDFLAGS)
depth_first_search_test_LDADD = $(GTEST_LIBS) -lgtest_main

check_PROGRAMS += depth_first_path_search_test
depth_first_path_search_test_SOURCES = ./algorithms/graphs/depth_first_path_search_test.cpp
depth_first_path_search_test_CPPFLAGS = -I$(top_srcdir)/src/algorithms/graphs $(GTEST_CPPFLAGS) 
depth_first_path_search_test_CXXFLAGS = $(GTEST_CXXFLAGS) 
depth_first_path_search_test_LDFLAGS = $(GTEST_LDFLAGS)
depth_first_path_search_test_LDADD = $(GTEST_LIBS) -lgtest_main

check_PROGRAMS += queue_test
queue_test_SOURCES = ./algorithms/datastructures/queue_test.cpp
queue_test_CPPFLAGS = -I$(top_srcdir)/src/algorithms/datastructures $(GTEST_CPPFLAGS) 
queue_test_CXXFLAGS = $(GTEST_CXXFLAGS) 
queue_test_LDFLAGS = $(GTEST_LDFLAGS)
queue_test_LDADD = $(GTEST_LIBS) -lgtest_main

check_PROGRAMS += connected_component_search_test
connected_component_search_test_SOURCES = ./algorithms/graphs/connected_component_search_test.cpp
connected_component_search_test_CPPFLAGS = -I$(top_srcdir)/src/algorithms/graphs $(GTEST_CPPFLAGS) 
connected_component_search_test_CXXFLAGS = $(GTEST_CXXFLAGS) 
connected_component_search_test_LDFLAGS = $(GTEST_LDFLAGS)
connected_component_search_test_LDADD = $(GTEST_LIBS) -lgtest_main

check_PROGRAMS += biparte_graph_test
biparte_graph_test_SOURCES = ./algorithms/graphs/biparte_graph_test.cpp
biparte_graph_test_CPPFLAGS = -I$(top_srcdir)/src/algorithms/graphs $(GTEST_CPPFLAGS) 
biparte_graph_test_CXXFLAGS = $(GTEST_CXXFLAGS) 
biparte_graph_test_LDFLAGS = $(GTEST_LDFLAGS)
biparte_graph_test_LDADD = $(GTEST_LIBS) -lgtest_main

check_PROGRAMS += cycle_graph_test
cycle_graph_test_SOURCES = ./algorithms/graphs/cycle_graph_test.cpp
cycle_graph_test_CPPFLAGS = -I$(top_srcdir)/src/algorithms/graphs $(GTEST_CPPFLAGS)
cycle_graph_test_CXXFLAGS = $(GTEST_CXXFLAGS)
cycle_graph_test_LDFLAGS = $(GTEST_LDFLAGS)
cycle_graph_test_LDADD = $(GTEST_LIBS) -lgtest_main

check_PROGRAMS += directed_graph_test
directed_graph_test_SOURCES = ./algorithms/graphs/directed_graph_test.cpp
directed_graph_test_CPPFLAGS = -I$(top_srcdir)/src/algorithms/graphs $(GTEST_CPPFLAGS)
directed_graph_test_CXXFLAGS = $(GTEST_CXXFLAGS)
directed_graph_test_LDFLAGS = $(GTEST_LDFLAGS)
directed_graph_test_LDADD = $(GTEST_LIBS) -lgtest_main

check_PROGRAMS += directed_graph_depth_first_search_test
directed_graph_depth_first_search_test_SOURCES = ./algorithms/graphs/directed_graph_depth_first_search_test.cpp
directed_graph_depth_first_search_test_CPPFLAGS = -I$(top_srcdir)/src/algorithms/graphs $(GTEST_CPPFLAGS)
directed_graph_depth_first_search_test_CXXFLAGS = $(GTEST_CXXFLAGS)
directed_graph_depth_first_search_test_LDFLAGS = $(GTEST_LDFLAGS)
directed_graph_depth_first_search_test_LDADD = $(GTEST_LIBS) -lgtest_main

check_PROGRAMS += directed_depth_first_path_search_test
directed_depth_first_path_search_test_SOURCES = ./algorithms/graphs/directed_depth_first_path_search_test.cpp
directed_depth_first_path_search_test_CPPFLAGS = -I$(top_srcdir)/src/algorithms/graphs $(GTEST_CPPFLAGS)
directed_depth_first_path_search_test_CXXFLAGS = $(GTEST_CXXFLAGS)
directed_depth_first_path_search_test_LDFLAGS = $(GTEST_LDFLAGS)
directed_depth_first_path_search_test_LDADD = $(GTEST_LIBS) -lgtest_main

check_PROGRAMS += directed_breadth_first_path_search_test
directed_breadth_first_path_search_test_SOURCES = ./algorithms/graphs/directed_breadth_first_path_search_test.cpp
directed_breadth_first_path_search_test_CPPFLAGS = -I$(top_srcdir)/src/algorithms/graphs $(GTEST_CPPFLAGS)
directed_breadth_first_path_search_test_CXXFLAGS = $(GTEST_CXXFLAGS)
directed_breadth_first_path_search_test_LDFLAGS = $(GTEST_LDFLAGS)
directed_breadth_first_path_search_test_LDADD = $(GTEST_LIBS) -lgtest_main

check_PROGRAMS += directed_cycle_test
directed_cycle_test_SOURCES = ./algorithms/graphs/directed_cycle_test.cpp
directed_cycle_test_CPPFLAGS = -I$(top_srcdir)/src/algorithms/graphs $(GTEST_CPPFLAGS)
directed_cycle_test_CXXFLAGS = $(GTEST_CXXFLAGS)
directed_cycle_test_LDFLAGS = $(GTEST_LDFLAGS)
directed_cycle_test_LDADD = $(GTEST_LIBS) -lgtest_main

check_PROGRAMS += directed_depth_first_order_test
directed_depth_first_order_test_SOURCES = ./algorithms/graphs/directed_depth_first_order_test.cpp
directed_depth_first_order_test_CPPFLAGS = -I$(top_srcdir)/src/algorithms/graphs $(GTEST_CPPFLAGS)
directed_depth_first_order_test_CXXFLAGS = $(GTEST_CXXFLAGS)
directed_depth_first_order_test_LDFLAGS = $(GTEST_LDFLAGS)
directed_depth_first_order_test_LDADD = $(GTEST_LIBS) -lgtest_main

check_PROGRAMS += topological_test
topological_test_SOURCES = ./algorithms/graphs/topological_test.cpp
topological_test_CPPFLAGS = -I$(top_srcdir)/src/algorithms/graphs $(GTEST_CPPFLAGS)
topological_test_CXXFLAGS = $(GTEST_CXXFLAGS)
topological_test_LDFLAGS = $(GTEST_LDFLAGS)
topological_test_LDADD = $(GTEST_LIBS) -lgtest_main

# Declare libraries and define tests here...

# Define programs run automatically by "make check"
TESTS = $(check_PROGRAMS)
