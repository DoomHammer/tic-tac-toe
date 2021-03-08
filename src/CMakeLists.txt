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

# Installation support

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)


## Create a Config file
configure_package_config_file(
        ${PROJECT_SOURCE_DIR}/cmake/tic-tac-toeConfig.cmake.in
        ${PROJECT_NAME}Config.cmake
        INSTALL_DESTINATION ${LIB_INSTALL_DIR}/${PROJECT_NAME}/cmake)

## Create a ConfigVersion file
write_basic_package_version_file(
        ${PROJECT_NAME}ConfigVersion.cmake
        VERSION ${PACKAGE_VERSION}
        COMPATIBILITY AnyNewerVersion)

## Install Config and ConfigVersion
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME})

## Create an export target
install(TARGETS tic-tac-toe tic-tac-toe-app
        EXPORT ${PROJECT_NAME}Targets
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})

## Create the Targets file using the export target
install(EXPORT ${PROJECT_NAME}Targets
        FILE ${PROJECT_NAME}Targets.cmake
        NAMESPACE ${PROJECT_NAME}::
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME})

## Install the headers
install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/ # last slash is important here
        DESTINATION include)

## Install the license and readme files
install(
        FILES ${PROJECT_SOURCE_DIR}/LICENSE
        DESTINATION ${CMAKE_INSTALL_DOCDIR})
