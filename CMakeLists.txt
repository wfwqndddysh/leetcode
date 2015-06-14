#==============================================================================
#cmake 版本
#==============================================================================
cmake_minimum_required(VERSION 2.8)

#==============================================================================
#项目logic name
#==============================================================================
project(leetcode)

#==============================================================================
#设置一些通用变量值，指定所有目录放于一个目录
#==============================================================================
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY         "${CMAKE_BINARY_DIR}/")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY         "${CMAKE_BINARY_DIR}/")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY         "${CMAKE_BINARY_DIR}/")

#==============================================================================
#处理构建类型
#==============================================================================
if(NOT CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE Debug)
endif()

#==============================================================================
#编译选项
#==============================================================================
set(CMAKE_C_COMPILER clang)
set(CMAKE_CXX_COMPILER clang++)
set(WARNING_FLAGS           "-Weverything -Wno-c++98-compat")
set(COMPILE_FLAGS           "-std=c++11")
set(DEBUG_FLAGS             "-DDEBUG -g3 -O0")
set(RELEASE_FLAGS           "-DNDEBUG -O3")
set(CMAKE_CXX_FLAGS_DEBUG   "${WARNING_FLAGS} ${COMPILE_FLAGS} ${DEBUG_FLAGS}")
set(CMAKE_CXX_FLAGS_RELEASE "${WARNING_FLAGS} ${COMPILE_FLAGS} ${RELEASE_FLAGS}")

#==============================================================================
# really start ...
#==============================================================================
add_executable(reverse_linked_list reverse_linked_list.cpp)
add_executable(isomorphic isomorphic.cpp)
add_executable(count_primes count_primes.cpp)
add_executable(remove_linked_list_elements remove_linked_list_elements.cpp)
add_executable(trie_prefix_tree trie_prefix_tree.cpp)
add_executable(happy_number happy_number.cpp)
add_executable(range_bitwise_and range_bitwise_and.cpp)
add_executable(bit_operation bit_operation.cpp)
add_executable(number_of_land number_of_land.cpp)
add_executable(binary_right_side_view binary_right_side_view.cpp)
add_executable(house_robber house_robber.cpp)
add_executable(number_of_1_bits number_of_1_bits.cpp)
add_executable(reverse_bits reverse_bits.cpp)
add_executable(rotate_array rotate_array.cpp)
add_executable(best_time_to_buy_and_sell_stock best_time_to_buy_and_sell_stock.cpp)
add_executable(best_time_to_buy_and_sell_stock_2 best_time_to_buy_and_sell_stock_2.cpp)
add_executable(best_time_to_buy_and_sell_stock_3 best_time_to_buy_and_sell_stock_3.cpp)
add_executable(best_time_to_buy_and_sell_stock_4 best_time_to_buy_and_sell_stock_4.cpp)
add_executable(repeated_dns_sequences repeated_dns_sequences.cpp)
add_executable(largest_number largest_number.cpp)
add_executable(dungeon_game dungeon_game.cpp)
add_executable(binary_search_tree_iterator binary_search_tree_iterator.cpp)
add_executable(factorial_trailing_zeroes factorial_trailing_zeroes.cpp)
add_executable(excel_sheet_column_cumber excel_sheet_column_cumber.cpp)
add_executable(majority_element majority_element.cpp)
add_executable(excel_sheet_solumn_title excel_sheet_solumn_title.cpp)
add_executable(fraction_to_recurring_decimal fraction_to_recurring_decimal.cpp)
add_executable(compare_version_numbers compare_version_numbers.cpp)
add_executable(maximum_gap maximum_gap.cpp)
add_executable(find_peak_element find_peak_element.cpp)
add_executable(intersection_of_two_linked_lists intersection_of_two_linked_lists.cpp)
add_executable(min_stack min_stack.cpp)
add_executable(find_minimum_in_rotated_sorted_array find_minimum_in_rotated_sorted_array.cpp)
add_executable(find_minimum_in_rotated_sorted_array_2 find_minimum_in_rotated_sorted_array_2.cpp)
add_executable(maximum_product_subarray maximum_product_subarray.cpp)
add_executable(reverse_words_in_a_string reverse_words_in_a_string.cpp)
add_executable(evaluate_reverse_polish_notation evaluate_reverse_polish_notation.cpp)
add_executable(max_points_on_a_line max_points_on_a_line.cpp)
add_executable(sort_list sort_list.cpp)
add_executable(insertion_sort_list insertion_sort_list.cpp)
add_executable(lru_cache lru_cache.cpp)
add_executable(binary_tree_postorder_traversal binary_tree_postorder_traversal.cpp)
add_executable(binary_tree_preorder_traversal binary_tree_preorder_traversal.cpp)
add_executable(reorder_list reorder_list.cpp)
add_executable(linked_list_cycle linked_list_cycle.cpp)
add_executable(linked_list_cycle_2 linked_list_cycle_2.cpp)
add_executable(word_break word_break.cpp)
add_executable(word_break_2 word_break_2.cpp)
add_executable(copy_list_with_random_pointer copy_list_with_random_pointer.cpp)
add_executable(single_number single_number.cpp)
add_executable(single_number_2 single_number_2.cpp)
add_executable(candy candy.cpp)
add_executable(gas_station gas_station.cpp)
add_executable(clone_graph clone_graph.cpp)
add_executable(palindrome_partitioning palindrome_partitioning.cpp)
add_executable(palindrome_partitioning_2 palindrome_partitioning_2.cpp)
add_executable(surrounded_regions surrounded_regions.cpp)
add_executable(longest_consecutive_sequence longest_consecutive_sequence.cpp)
add_executable(sum_root_to_leaf_numbers sum_root_to_leaf_numbers.cpp)
add_executable(word_ladder word_ladder.cpp)
add_executable(word_ladder_2 word_ladder_2.cpp)
add_executable(valid_palindrome valid_palindrome.cpp)
add_executable(binary_tree_maximum_path_sum binary_tree_maximum_path_sum.cpp)
add_executable(triangle triangle.cpp)
add_executable(pascal_triangle pascal_triangle.cpp)
add_executable(pascal_triangle_2 pascal_triangle_2.cpp)
add_executable(populating_next_right_pointers_in_each_node populating_next_right_pointers_in_each_node.cpp)
add_executable(populating_next_right_pointers_in_each_node_2 populating_next_right_pointers_in_each_node_2.cpp)
add_executable(distinct_subsequences distinct_subsequences.cpp)
add_executable(flatten_binary_tree_to_linked_list flatten_binary_tree_to_linked_list.cpp)
add_executable(path_sum path_sum.cpp)
add_executable(path_sum_2 path_sum_2.cpp)
add_executable(minimum_depth_of_binary_tree minimum_depth_of_binary_tree.cpp)
add_executable(balanced_binary_tree balanced_binary_tree.cpp)
add_executable(convert_sorted_list_to_binary_search_tree convert_sorted_list_to_binary_search_tree.cpp)
add_executable(sorted_array_to_binary_search_tree sorted_array_to_binary_search_tree.cpp)
add_executable(binary_tree_level_order_traversal_2 binary_tree_level_order_traversal_2.cpp)
add_executable(construct_binary_tree_from_inorder_and_postorder_traversal construct_binary_tree_from_inorder_and_postorder_traversal.cpp)

