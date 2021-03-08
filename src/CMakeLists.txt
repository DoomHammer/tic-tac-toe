# Target definitions

add_library(tic-tac-toe STATIC tic-tac-toe.cpp)
set_target_properties(tic-tac-toe PROPERTIES CXX_EXTENSIONS OFF)
target_compile_features(tic-tac-toe INTERFACE cxx_std_17 PRIVATE cxx_std_20)
target_include_directories(tic-tac-toe PUBLIC
        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>)
