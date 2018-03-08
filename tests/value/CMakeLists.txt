cmake_minimum_required(VERSION 3.5)

add_executable(v1 ${CMAKE_CURRENT_LIST_DIR}/construct_default.cpp)
add_executable(v2 ${CMAKE_CURRENT_LIST_DIR}/construct_nodefault.cpp)

add_executable(v3 ${CMAKE_CURRENT_LIST_DIR}/construct_copy.cpp)
add_executable(v4 ${CMAKE_CURRENT_LIST_DIR}/construct_move.cpp)

add_executable(v5 ${CMAKE_CURRENT_LIST_DIR}/assign_copy.cpp)
add_executable(v6 ${CMAKE_CURRENT_LIST_DIR}/assign_move.cpp)

add_executable(v7 ${CMAKE_CURRENT_LIST_DIR}/use_lazy.cpp)
add_executable(v8 ${CMAKE_CURRENT_LIST_DIR}/use_eager.cpp)

add_library(value 
        ${CMAKE_CURRENT_LIST_DIR}/value.cpp
        ${CMAKE_CURRENT_LIST_DIR}/value.h
        )

target_link_libraries(value smart_pimpl)

target_link_libraries(v1 value)
target_link_libraries(v2 value)
target_link_libraries(v3 value)
target_link_libraries(v4 value)
target_link_libraries(v5 value)
target_link_libraries(v6 value)
target_link_libraries(v7 value)
target_link_libraries(v8 value)

add_test(NAME value.construct.default COMMAND v1)
add_test(NAME value.construct.nodefault COMMAND v2)

add_test(NAME value.construct.copy COMMAND v3)
# add_test(NAME value.construct.move COMMAND v4)

# add_test(NAME value.assign.copy COMMAND v5)
# add_test(NAME value.assign.move COMMAND v6)

# add_test(NAME value.use.lazy COMMAND v7)
# add_test(NAME value.use.eager COMMAND v8)