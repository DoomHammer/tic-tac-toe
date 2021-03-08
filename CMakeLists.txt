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