cmake_minimum_required(VERSION 3.5)

add_executable(value "")
target_sources(value
        PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/main.cpp
        ${CMAKE_CURRENT_LIST_DIR}/value.cpp
        ${CMAKE_CURRENT_LIST_DIR}/value.h
        )

target_link_libraries(value smart_pimpl)

add_test(NAME value.default COMMAND value)