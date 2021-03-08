cmake_minimum_required(VERSION 3.15...3.19)

project(tic-tac-toe
        LANGUAGES CXX)

find_program(CCACHE_PROGRAM ccache)
if (CCACHE_PROGRAM)
    set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE "${CCACHE_PROGRAM}")
endif ()

add_subdirectory(src)
