cmake_minimum_required(VERSION 3.15...3.19)

project(tic-tac-toe
        VERSION 0.0.1
        LANGUAGES CXX)

list(APPEND CMAKE_PREFIX_PATH "${CMAKE_BINARY_DIR}")


find_program(CCACHE_PROGRAM ccache)
if (CCACHE_PROGRAM)
    set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE "${CCACHE_PROGRAM}")
endif ()

add_subdirectory(src)


# Testing


if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    include(CTest)
    if(BUILD_TESTING)
        add_subdirectory(test)
    endif()
endif()


# Conan Support


configure_file("${PROJECT_SOURCE_DIR}/conan/conanfile.py.in"
        "${CMAKE_CURRENT_BINARY_DIR}/conan/conanfile.py" @ONLY)

add_custom_target(
        conan
        COMMAND
        ${CMAKE_COMMAND} -E copy_directory ${PROJECT_SOURCE_DIR}/conan/test_package/
        ${CMAKE_CURRENT_BINARY_DIR}/conan/test_package
        COMMAND conan create . tic-tac-toe/testing -s build_type=${CMAKE_BUILD_TYPE}
        DEPENDS "${CMAKE_CURRENT_BINARY_DIR}/conan/conanfile.py"
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/conan
        VERBATIM)