cmake_minimum_required(VERSION 3.5)

include(CTest)

macro(do_n_tests name cmd n)
    foreach (i RANGE ${n})
        add_test(NAME ${name}_${i} COMMAND ${cmd})
    endforeach ()
endmacro()

add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/entity)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/value)

# Not supported yet
#add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/pointer)