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

check_PROGRAMS += edge_test
edge_test_SOURCES = ./algorithms/graphs/edge_test.cpp
edge_test_CPPFLAGS = -I$(top_srcdir)/src/algorithms/graphs $(GTEST_CPPFLAGS)
edge_test_CXXFLAGS = $(GTEST_CXXFLAGS)
edge_test_LDFLAGS = $(GTEST_LDFLAGS)
edge_test_LDADD = $(GTEST_LIBS) -lgtest_main

check_PROGRAMS += edge_weighted_graph_test
edge_weighted_graph_test_SOURCES = ./algorithms/graphs/edge_weighted_graph_test.cpp
edge_weighted_graph_test_CPPFLAGS = -I$(top_srcdir)/src/algorithms/graphs $(GTEST_CPPFLAGS)
edge_weighted_graph_test_CXXFLAGS = $(GTEST_CXXFLAGS)
edge_weighted_graph_test_LDFLAGS = $(GTEST_LDFLAGS)
edge_weighted_graph_test_LDADD = $(GTEST_LIBS) -lgtest_main

check_PROGRAMS += smart_pointers_test
smart_pointers_test_SOURCES = ./fundamentals/pointers/smart_pointers_test.cpp
smart_pointers_test_CPPFLAGS = -I$(top_srcdir)/src/fundamentals/pointers $(GTEST_CPPFLAGS)
smart_pointers_test_CXXFLAGS = $(GTEST_CXXFLAGS)
smart_pointers_test_LDFLAGS = $(GTEST_LDFLAGS)
smart_pointers_test_LDADD = $(GTEST_LIBS) -lgtest_main

check_PROGRAMS += casts_test
casts_test_SOURCES = ./fundamentals/casts/casts_test.cpp
casts_test_CPPFLAGS = -I$(top_srcdir)/src/fundamentals/casts $(GTEST_CPPFLAGS)
casts_test_CXXFLAGS = $(GTEST_CXXFLAGS)
casts_test_LDFLAGS = $(GTEST_LDFLAGS)
casts_test_LDADD = $(GTEST_LIBS) -lgtest_main

check_PROGRAMS += copy_test
copy_test_SOURCES = ./fundamentals/constructors/copy_test.cpp
copy_test_CPPFLAGS = -I$(top_srcdir)/src/fundamentals/constructors $(GTEST_CPPFLAGS)
copy_test_CXXFLAGS = $(GTEST_CXXFLAGS)
copy_test_LDFLAGS = $(GTEST_LDFLAGS)
copy_test_LDADD = $(GTEST_LIBS) -lgtest_main

check_PROGRAMS += array_test
array_test_SOURCES = ./fundamentals/arrays/array_test.cpp
array_test_CPPFLAGS = -I$(top_srcdir)/src/arrays/constructors $(GTEST_CPPFLAGS)
array_test_CXXFLAGS = $(GTEST_CXXFLAGS)
array_test_LDFLAGS = $(GTEST_LDFLAGS)
array_test_LDADD = $(GTEST_LIBS) -lgtest_main

check_PROGRAMS += decltype_test
decltype_test_SOURCES = ./fundamentals/types/decltype_test.cpp
decltype_test_CPPFLAGS = -I$(top_srcdir)/src/fundamentals/types $(GTEST_CPPFLAGS)
decltype_test_CXXFLAGS = $(GTEST_CXXFLAGS)
decltype_test_LDFLAGS = $(GTEST_LDFLAGS)
decltype_test_LDADD = $(GTEST_LIBS) -lgtest_main

check_PROGRAMS += template_function_test
template_function_test_SOURCES = ./templates/template_function_test.cpp 
template_function_test_CPPFLAGS = -I$(top_srcdir)/src/templates $(GTEST_CPPFLAGS)
template_function_test_CXXFLAGS = $(GTEST_CXXFLAGS)
template_function_test_LDFLAGS = $(GTEST_LDFLAGS)
template_function_test_LDADD = $(GTEST_LIBS) -lgtest_main

check_PROGRAMS += template_class_test
template_class_test_SOURCES = ./templates/template_class_test.cc ../src/templates/template-class.cc
template_class_test_CPPFLAGS = -I$(top_srcdir)/src/templates $(GTEST_CPPFLAGS)
template_class_test_CXXFLAGS = $(GTEST_CXXFLAGS)
template_class_test_LDFLAGS = $(GTEST_LDFLAGS)
template_class_test_LDADD = $(GTEST_LIBS) -lgtest_main

check_PROGRAMS += const_test
const_test_SOURCES = ./fundamentals/const_test.cc
const_test_CPPFLAGS = -I$(top_srcdir)/src/fundamentals $(GTEST_CPPFLAGS)
const_test_CXXFLAGS = $(GTEST_CXXFLAGS)
const_test_LDFLAGS = $(GTEST_LDFLAGS)
const_test_LDADD = $(GTEST_LIBS) -lgtest_main

check_PROGRAMS += move_test
move_test_SOURCES = ./fundamentals/constructors/move_test.cc
move_test_CPPFLAGS = -I$(top_srcdir)/src/fundamentals/constructors $(GTEST_CPPFLAGS)
move_test_CXXFLAGS = $(GTEST_CXXFLAGS)
move_test_LDFLAGS = $(GTEST_LDFLAGS)
move_test_LDADD = $(GTEST_LIBS) -lgtest_main

check_PROGRAMS += ambig_test
ambig_test_SOURCES = ./classes/ambig_test.cc
ambig_test_CPPFLAGS = -I$(top_srcdir)/src/classes $(GTEST_CPPFLAGS)
ambig_test_CXXFLAGS = $(GTEST_CXXFLAGS)
ambig_test_LDFLAGS = $(GTEST_LDFLAGS)
ambig_test_LDADD = $(GTEST_LIBS) -lgtest_main

check_PROGRAMS += visibility_test
visibility_test_SOURCES = ./fundamentals/visibility_test.cc
visibility_test_CPPFLAGS = -I$(top_srcdir)/src/fundamentals $(GTEST_CPPFLAGS) -fvisibility=hidden -fvisibility-inlines-hidden
visibility_test_CXXFLAGS = $(GTEST_CXXFLAGS) -std=c++11 -fvisibility=hidden -fvisibility-inlines-hidden
visibility_test_LDFLAGS = $(GTEST_LDFLAGS) -std=c++11 -fvisibility=hidden -fvisibility-inlines-hidden
visibility_test_LDADD = $(GTEST_LIBS) -lgtest_main

check_PROGRAMS += non-virtual-destructor_test
non_virtual_destructor_test_SOURCES = ./fundamentals/constructors/non-virtual-destructor_test.cc
non_virtual_destructor_test_CPPFLAGS = -I$(top_srcdir)/src/fundamentals/constructors $(GTEST_CPPFLAGS)
non_virtual_destructor_test_CXXFLAGS = $(GTEST_CXXFLAGS)
non_virtual_destructor_test_LDFLAGS = $(GTEST_LDFLAGS)
non_virtual_destructor_test_LDADD = $(GTEST_LIBS) -lgtest_main

check_PROGRAMS += virtual-destructor_test
virtual_destructor_test_SOURCES = ./fundamentals/constructors/virtual-destructor_test.cc
virtual_destructor_test_CPPFLAGS = -I$(top_srcdir)/src/fundamentals/constructors $(GTEST_CPPFLAGS)
virtual_destructor_test_CXXFLAGS = $(GTEST_CXXFLAGS)
virtual_destructor_test_LDFLAGS = $(GTEST_LDFLAGS)
virtual_destructor_test_LDADD = $(GTEST_LIBS) -lgtest_main

check_PROGRAMS += default-virtual-destructor_test
default_virtual_destructor_test_SOURCES = ./fundamentals/constructors/default-virtual-destructor_test.cc
default_virtual_destructor_test_CPPFLAGS = -I$(top_srcdir)/src/fundamentals/constructors $(GTEST_CPPFLAGS)
default_virtual_destructor_test_CXXFLAGS = $(GTEST_CXXFLAGS)
default_virtual_destructor_test_LDFLAGS = $(GTEST_LDFLAGS)
default_virtual_destructor_test_LDADD = $(GTEST_LIBS) -lgtest_main

check_PROGRAMS += macros_test
macros_test_SOURCES = ./fundamentals/macros/macros_test.cc
macros_test_CPPFLAGS = -I$(top_srcdir)/src/fundamentals/macros $(GTEST_CPPFLAGS)
macros_test_CXXFLAGS = $(GTEST_CXXFLAGS)
macros_test_LDFLAGS = $(GTEST_LDFLAGS)
macros_test_LDADD = $(GTEST_LIBS) -lgtest_main

check_PROGRAMS += vararg_test
vararg_test_SOURCES = ./fundamentals/macros/vararg_test.cc
vararg_test_CPPFLAGS = -I$(top_srcdir)/src/fundamentals/macros $(GTEST_CPPFLAGS)
vararg_test_CXXFLAGS = $(GTEST_CXXFLAGS)
vararg_test_LDFLAGS = $(GTEST_LDFLAGS)
vararg_test_LDADD = $(GTEST_LIBS) -lgtest_main

check_PROGRAMS += util_test
util_test_SOURCES = ./fundamentals/casts/util_test.cc
util_test_CPPFLAGS = -I$(top_srcdir)/src/fundamentals/casts -I$(top_srcdir)/src/algorithms/datastructures $(GTEST_CPPFLAGS)
util_test_CXXFLAGS = $(GTEST_CXXFLAGS)
util_test_LDFLAGS = $(GTEST_LDFLAGS)
util_test_LDADD = $(GTEST_LIBS) -lgtest_main

check_PROGRAMS += member_pointer_test
member_pointer_test_SOURCES = ./fundamentals/pointers/member_pointer_test.cc
member_pointer_test_CPPFLAGS = -I$(top_srcdir)/src/fundamentals/pointers $(GTEST_CPPFLAGS)
member_pointer_test_CXXFLAGS = $(GTEST_CXXFLAGS)
member_pointer_test_LDFLAGS = $(GTEST_LDFLAGS)
member_pointer_test_LDADD = $(GTEST_LIBS) -lgtest_main

check_PROGRAMS += protected_test
protected_test_SOURCES = ./fundamentals/protected_test.cc
protected_test_CPPFLAGS = -I$(top_srcdir)/src/pointers $(GTEST_CPPFLAGS)
protected_test_CXXFLAGS = $(GTEST_CXXFLAGS)
protected_test_LDFLAGS = $(GTEST_LDFLAGS)
protected_test_LDADD = $(GTEST_LIBS) -lgtest_main

check_PROGRAMS += malloc_test
malloc_test_SOURCES = ./fundamentals/malloc_test.cc
malloc_test_CPPFLAGS = -I$(top_srcdir)/src/pointers $(GTEST_CPPFLAGS)
malloc_test_CXXFLAGS = $(GTEST_CXXFLAGS)
malloc_test_LDFLAGS = $(GTEST_LDFLAGS)
malloc_test_LDADD = $(GTEST_LIBS) -lgtest_main

check_PROGRAMS += forward_list_test
forward_list_test_SOURCES = ./stl/forward_list_test.cc
forward_list_test_CPPFLAGS = $(GTEST_CPPFLAGS)
forward_list_test_CXXFLAGS = $(GTEST_CXXFLAGS)
forward_list_test_LDFLAGS = $(GTEST_LDFLAGS)
forward_list_test_LDADD = $(GTEST_LIBS) -lgtest_main

check_PROGRAMS += varargs_test
varargs_test_SOURCES = ./fundamentals/varargs/varargs_test.cc
varargs_test_CPPFLAGS = -I$(top_srcdir)/src/fundamentals/varargs $(GTEST_CPPFLAGS)
varargs_test_CXXFLAGS = $(GTEST_CXXFLAGS)
varargs_test_LDFLAGS = $(GTEST_LDFLAGS)
varargs_test_LDADD = $(GTEST_LIBS) -lgtest_main

check_PROGRAMS += pimpl_test
pimpl_test_SOURCES = ./patterns/pimpl_test.cc ../src/patterns/pimpl.cc
pimpl_test_CPPFLAGS = -I$(top_srcdir)/src/patterns $(GTEST_CPPFLAGS) 
pimpl_test_CXXFLAGS = $(GTEST_CXXFLAGS)
pimpl_test_LDFLAGS = $(GTEST_LDFLAGS)
pimpl_test_LDADD = $(GTEST_LIBS) -lgtest_main

check_PROGRAMS += simple_factory_test
simple_factory_test_SOURCES = ./patterns/simple_factory_test.cc ../src/patterns/openssl_1_0_2e.cc ../src/patterns/simple_factory.cc
simple_factory_test_CPPFLAGS = -I$(top_srcdir)/src/patterns $(GTEST_CPPFLAGS) 
simple_factory_test_CXXFLAGS = $(GTEST_CXXFLAGS)
simple_factory_test_LDFLAGS = $(GTEST_LDFLAGS)
simple_factory_test_LDADD = $(GTEST_LIBS) -lgtest_main

# Declare libraries and define tests here...

# Define programs run automatically by "make check"
TESTS = $(check_PROGRAMS)
