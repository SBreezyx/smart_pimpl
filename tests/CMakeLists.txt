cmake_minimum_required(VERSION 3.5)

include(CTest)

add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/entity)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/value)

# Not supported yet
#add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/pointer)