cmake_minimum_required(VERSION 3.15)

project(accu_workshop_building_and_packaging)

add_executable(tic-tac-toe tic-tac-toe.cpp)
target_compile_features(tic-tac-toe PRIVATE cxx_std_20)

