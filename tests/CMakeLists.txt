cmake_minimum_required(VERSION 3.5)

include(CTest)

macro(do_n_tests name cmd n)
    foreach (i RANGE ${n})
        add_test(NAME ${name}_${i} COMMAND ${cmd} ${i})
    endforeach ()
endmacro()

add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/smart_pimpl)

# Needs more work
#add_subdirectory(${CMAKE_CURRENT_LIST_DIR}value_ptr)
