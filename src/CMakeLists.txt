cmake_minimum_required(VERSION 3.5)

add_library(smart_pimpl INTERFACE)

target_include_directories(smart_pimpl
        INTERFACE
        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/src>
        )

if (INSTALL)
    install(TARGETS smart_pimpl
            EXPORT smart_pimplTargets
            INCLUDES DESTINATION include
    )

    include(CMakePackageConfigHelpers)
    write_basic_package_version_file(
            "${PROJECT_BINARY_DIR}/smart_pimplConfigVersion.cmake"
            VERSION 1.0.0
            COMPATIBILITY AnyNewerVersion
    )

    configure_package_config_file(
            "${PROJECT_SOURCE_DIR}/cmake/smart_pimplConfig.cmake.in"
            "${PROJECT_BINARY_DIR}/smart_pimplConfig.cmake"
            INSTALL_DESTINATION share/cmake/smart_pimpl
    )

    install(EXPORT smart_pimplTargets
            DESTINATION share/cmake/smart_pimpl
            )

    install(FILES
            ${PROJECT_BINARY_DIR}/smart_pimplConfig.cmake
            ${PROJECT_BINARY_DIR}/smart_pimplConfigVersion.cmake
            DESTINATION share/cmake/smart_pimpl
            )

    install(DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/smart_pimpl
            DESTINATION include)
endif ()