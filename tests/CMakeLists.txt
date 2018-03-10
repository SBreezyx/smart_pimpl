cmake_minimum_required(VERSION 3.5)

include(CTest)

list(APPEND test_exes
        cons_def
        cons_nodef
        cons_cp
        cons_mv
        cons_nm
        cons_secret
        ass_cp
        ass_mv
        use_lz
        use_eg
        use_polyif
        )

list(APPEND test_srcs
        ${CMAKE_CURRENT_LIST_DIR}/construct_default.cpp
        ${CMAKE_CURRENT_LIST_DIR}/construct_nodefault.cpp
        ${CMAKE_CURRENT_LIST_DIR}/construct_copy.cpp
        ${CMAKE_CURRENT_LIST_DIR}/construct_move.cpp
        ${CMAKE_CURRENT_LIST_DIR}/construct_named.cpp
        ${CMAKE_CURRENT_LIST_DIR}/construct_secret.cpp
        ${CMAKE_CURRENT_LIST_DIR}/assign_copy.cpp
        ${CMAKE_CURRENT_LIST_DIR}/assign_move.cpp
        ${CMAKE_CURRENT_LIST_DIR}/use_lazy.cpp
        ${CMAKE_CURRENT_LIST_DIR}/use_eager.cpp
        ${CMAKE_CURRENT_LIST_DIR}/use_poly_interface.cpp
        )

list(APPEND test_names
        cons.def
        cons.nodef
        cons.cp
        cons.mv
        cons.nm
        cons.secret
        ass.cp
        ass.mv
        use.lz
        use.eg
        use.polyif
        )

list(LENGTH test_exes ntest)

foreach (i RANGE ${ntest})
    if (${i} EQUAL ${ntest})
        break()
    endif ()

    list(GET test_exes ${i} exe)
    list(GET test_srcs ${i} src)
    list(GET test_names ${i} name)

    foreach (c e r)
        set(exe_name ${c}_${exe})
        set(test_name ${c}.${name})
        set(src_name ${src})

        try_compile(DID_COMPILE ${CMAKE_CURRENT_BINARY_DIR}
                SOURCES ${src_name} ${CMAKE_CURRENT_LIST_DIR}/test.cpp
                COMPILE_DEFINITIONS "-D${c} -fconcepts -I/home/simon/Code/smart_pimpl/src"
                CXX_STANDARD 17
                CXX_STANDARD_REQUIRED TRUE
                OUTPUT_VARIABLE res
                )

        if (DID_COMPILE)
            add_executable(${exe_name} ${src_name} ${CMAKE_CURRENT_LIST_DIR}/test.h ${CMAKE_CURRENT_LIST_DIR}/test.cpp)
            target_link_libraries(${exe_name} smart_pimpl)
            target_compile_definitions(${exe_name} PRIVATE ${c})

            add_test(NAME ${test_name} COMMAND ${exe_name})
        endif ()

    endforeach ()
endforeach ()
