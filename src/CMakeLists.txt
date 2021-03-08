# Target definitions

add_library(tic-tac-toe STATIC tic-tac-toe.cpp)
add_library(${PROJECT_NAME}::tic-tac-toe ALIAS tic-tac-toe)
set_target_properties(tic-tac-toe PROPERTIES CXX_EXTENSIONS OFF)
target_compile_features(tic-tac-toe INTERFACE cxx_std_17 PRIVATE cxx_std_20)
target_include_directories(tic-tac-toe PUBLIC
        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>)

add_executable(tic-tac-toe-app main.cpp)
add_executable(${PROJECT_NAME}::tic-tac-toe-app ALIAS tic-tac-toe-app)
set_target_properties(tic-tac-toe-app PROPERTIES
        CXX_EXTENSIONS OFF
        OUTPUT_NAME tic-tac-toe
        )
target_compile_features(tic-tac-toe-app PRIVATE cxx_std_11)
target_link_libraries(tic-tac-toe-app PRIVATE tic-tac-toe)
