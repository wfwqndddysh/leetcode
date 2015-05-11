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

