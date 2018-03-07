cmake_minimum_required(VERSION 3.9)
project(smart_pimpl)

set(CMAKE_CXX_STANDARD 17)

add_library(smart_pimpl INTERFACE)

target_sources(smart_pimpl
        INTERFACE
        ${CMAKE_CURRENT_LIST_DIR}/include/smart_pimpl/pimpl.hpp
        ${CMAKE_CURRENT_LIST_DIR}/include/smart_pimpl/internal/impl_ptr.hpp
        ${CMAKE_CURRENT_LIST_DIR}/include/smart_pimpl/internal/impl_ptr.inl
        ${CMAKE_CURRENT_LIST_DIR}/include/smart_pimpl/internal/helpers.hpp
        )

target_include_directories(smart_pimpl
        INTERFACE
        ${CMAKE_CURRENT_LIST_DIR}/include
        )

add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/tests)