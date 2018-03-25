cmake_minimum_required(VERSION 3.5)
project(SmartPimpl)

set(CMAKE_CXX_STANDARD 17)

if (UNIX)
    set(CMAKE_CXX_FLAGS_DEBUG "-g -Wall -Werror")
    set(CMAKE_CXX_FLAGS_RELEASE "-Od")
elseif (MSVC)
    set(CMAKE_CXX_FLAGS_RELEASE "/Od")
endif ()

option(INSTALL "Set install target" ON)
option(BUILD_TESTING "Build tests" ON)

add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/src)

if (BUILD_TESTING)
    add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/tests)
endif ()
