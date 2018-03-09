cmake_minimum_required(VERSION 3.5)

add_executable(cons_and_ass ${CMAKE_CURRENT_LIST_DIR}/tests/construction_and_assignment.cpp)
target_link_libraries(cons_and_ass value_ptr)