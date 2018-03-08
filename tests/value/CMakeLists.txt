cmake_minimum_required(VERSION 3.5)

add_executable(value_cons_def ${CMAKE_CURRENT_LIST_DIR}/construct_default.cpp)
add_executable(value_cons_nodef ${CMAKE_CURRENT_LIST_DIR}/construct_nodefault.cpp)

add_executable(value_cons_cp ${CMAKE_CURRENT_LIST_DIR}/construct_copy.cpp)
add_executable(value_cons_mv ${CMAKE_CURRENT_LIST_DIR}/construct_move.cpp)

add_executable(value_ass_cp ${CMAKE_CURRENT_LIST_DIR}/assign_copy.cpp)
add_executable(value_ass_mv ${CMAKE_CURRENT_LIST_DIR}/assign_move.cpp)

add_executable(value_use_lz ${CMAKE_CURRENT_LIST_DIR}/use_lazy.cpp)
add_executable(value_use_eg ${CMAKE_CURRENT_LIST_DIR}/use_eager.cpp)

add_library(value
        ${CMAKE_CURRENT_LIST_DIR}/value.cpp
        ${CMAKE_CURRENT_LIST_DIR}/value.h
        )

target_link_libraries(value smart_pimpl)

target_link_libraries(value_cons_def value)
target_link_libraries(value_cons_nodef value)
target_link_libraries(value_cons_cp value)
target_link_libraries(value_cons_mv value)
target_link_libraries(value_ass_cp value)
target_link_libraries(value_ass_mv value)
target_link_libraries(value_use_lz value)
target_link_libraries(value_use_eg value)

# run each test twice to make sure that environment doesnt hide any bugs
do_n_tests(value.construct.default value_cons_def 2)
do_n_tests(value.construct.nodefault value_cons_nodef 2)

do_n_tests(value.construct.copy value_cons_cp 2)
do_n_tests(value.construct.move value_cons_mv 2)

do_n_tests(value.assign.copy value_ass_cp 2)
do_n_tests(value.assign.move value_ass_mv 2)

do_n_tests(value.use.lazy value_use_lz 2)
do_n_tests(value.use.eager value_use_eg 2)