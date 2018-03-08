cmake_minimum_required(VERSION 3.5)

add_library(smart_pimpl INTERFACE)

target_sources(smart_pimpl
        INTERFACE
        ${CMAKE_CURRENT_LIST_DIR}/smart_pimpl/pimpl.hpp
        ${CMAKE_CURRENT_LIST_DIR}/smart_pimpl/internal/base.hpp
        ${CMAKE_CURRENT_LIST_DIR}/smart_pimpl/internal/impl_ptr.hpp
        ${CMAKE_CURRENT_LIST_DIR}/smart_pimpl/internal/impl_ptr.inl
        ${CMAKE_CURRENT_LIST_DIR}/smart_pimpl/internal/helpers.hpp
        )

target_include_directories(smart_pimpl
        INTERFACE
        ${CMAKE_CURRENT_LIST_DIR}
        )