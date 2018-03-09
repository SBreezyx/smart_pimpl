cmake_minimum_required(VERSION 3.5)

add_library(value
        ${CMAKE_CURRENT_LIST_DIR}/value/value.cpp
        ${CMAKE_CURRENT_LIST_DIR}/value/value.h
        )

target_link_libraries(value smart_pimpl)

add_library(reference
        ${CMAKE_CURRENT_LIST_DIR}/reference/reference.cpp
        ${CMAKE_CURRENT_LIST_DIR}/reference/reference.h
        )

target_link_libraries(reference smart_pimpl)

add_library(entity
        ${CMAKE_CURRENT_LIST_DIR}/entity/Entity.cpp
        ${CMAKE_CURRENT_LIST_DIR}/entity/Entity.h
        )

target_link_libraries(entity smart_pimpl)

add_executable(cons_def ${CMAKE_CURRENT_LIST_DIR}/tests/construct_default.cpp)
add_executable(cons_nodef ${CMAKE_CURRENT_LIST_DIR}/tests/construct_nodefault.cpp)

add_executable(cons_cp ${CMAKE_CURRENT_LIST_DIR}/tests/construct_copy.cpp)
add_executable(cons_mv ${CMAKE_CURRENT_LIST_DIR}/tests/construct_move.cpp)

add_executable(ass_cp ${CMAKE_CURRENT_LIST_DIR}/tests/assign_copy.cpp)
add_executable(ass_mv ${CMAKE_CURRENT_LIST_DIR}/tests/assign_move.cpp)

add_executable(use_lz ${CMAKE_CURRENT_LIST_DIR}/tests/use_lazy.cpp)
add_executable(use_eg ${CMAKE_CURRENT_LIST_DIR}/tests/use_eager.cpp)

target_link_libraries(cons_def value)
target_link_libraries(cons_nodef value)
target_link_libraries(cons_cp value)
target_link_libraries(cons_mv value)
target_link_libraries(ass_cp value)
target_link_libraries(ass_mv value)
target_link_libraries(use_lz value)
target_link_libraries(use_eg value)

# run each test twice to make sure that environment doesnt hide any bugs
do_n_tests(construct.default value_cons_def 2)
do_n_tests(construct.nodefault value_cons_nodef 2)

do_n_tests(construct.copy value_cons_cp 2)
do_n_tests(construct.move value_cons_mv 2)

do_n_tests(assign.copy value_ass_cp 2)
do_n_tests(assign.move value_ass_mv 2)

do_n_tests(use.lazy value_use_lz 2)
do_n_tests(use.eager value_use_eg 2)