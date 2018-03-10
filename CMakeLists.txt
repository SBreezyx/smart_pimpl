cmake_minimum_required(VERSION 3.5)
project(SmartPimpl)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "-fconcepts")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-Od")

option(INSTALL "Set install target" ON)
option(BUILD_TESTING "Build tests" OFF)

add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/src)

if (BUILD_TESTING)
    add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/tests)
endif ()
