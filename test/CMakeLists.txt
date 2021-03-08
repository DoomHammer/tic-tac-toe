add_executable(unittest test.cpp)
add_executable(${PROJECT_NAME}::unittest ALIAS unittest)
target_link_libraries(unittest tic-tac-toe)
add_test(NAME unittest COMMAND ./unittest)