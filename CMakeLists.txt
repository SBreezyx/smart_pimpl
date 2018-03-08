cmake_minimum_required(VERSION 3.9)
project(smart_pimpl)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/src)

add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/tests)