cmake_minimum_required(VERSION 3.15)

project(tic-tac-toe
        VERSION 0.0.1
        LANGUAGES CXX)

find_program(CCACHE_PROGRAM ccache)
if (CCACHE_PROGRAM)
    set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE "${CCACHE_PROGRAM}")
endif ()

add_executable(tic-tac-toe tic-tac-toe.cpp)
target_compile_features(tic-tac-toe PRIVATE cxx_std_20)
