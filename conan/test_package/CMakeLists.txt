cmake_minimum_required(VERSION 3.15)
project(PackageTest CXX)

find_package(tic-tac-toe REQUIRED)

add_executable(example example.cpp)
target_link_libraries(example PRIVATE tic-tac-toe::tic-tac-toe)
target_compile_features(example PRIVATE cxx_std_17)

# CTest tests can be added here
