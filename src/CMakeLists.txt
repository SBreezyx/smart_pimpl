cmake_minimum_required(VERSION 3.5)

add_library(cs INTERFACE)
target_sources(cs INTERFACE ${CMAKE_CURRENT_LIST_DIR}/concepts.hpp)

add_library(value_ptr INTERFACE)
target_sources(value_ptr
        INTERFACE
        ${CMAKE_CURRENT_LIST_DIR}/value_ptr/internal/default_copy.hpp
        ${CMAKE_CURRENT_LIST_DIR}/value_ptr/internal/default_delete.hpp
        ${CMAKE_CURRENT_LIST_DIR}/value_ptr/value_ptr.hpp
        ${CMAKE_CURRENT_LIST_DIR}/value_ptr/internal/value_ptr_ops.inl
        )
target_include_directories(value_ptr INTERFACE ${CMAKE_CURRENT_LIST_DIR})

target_link_libraries(value_ptr INTERFACE cs)

add_library(smart_pimpl INTERFACE)

target_sources(smart_pimpl
        INTERFACE
        ${CMAKE_CURRENT_LIST_DIR}/smart_pimpl/pimpl.hpp
        ${CMAKE_CURRENT_LIST_DIR}/smart_pimpl/internal/base.hpp
        ${CMAKE_CURRENT_LIST_DIR}/smart_pimpl/internal/helpers.hpp
        )

target_include_directories(smart_pimpl
        INTERFACE
        ${CMAKE_CURRENT_LIST_DIR}
        )

target_link_libraries(smart_pimpl INTERFACE value_ptr)