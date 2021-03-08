find_package(Catch2 REQUIRED)
include(Catch)

add_executable(unittest test.cpp)
add_executable(${PROJECT_NAME}::unittest ALIAS unittest)

target_link_libraries(unittest tic-tac-toe catch2::catch2)
catch_discover_tests(unittest)
