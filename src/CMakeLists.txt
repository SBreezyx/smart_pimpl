cmake_minimum_required(VERSION 3.5)

add_library(smart_pimpl INTERFACE)

target_sources(smart_pimpl
        INTERFACE
        ${CMAKE_CURRENT_LIST_DIR}/pimpl.hpp
        )

target_include_directories(smart_pimpl
        INTERFACE
        ${CMAKE_CURRENT_LIST_DIR}
        )
