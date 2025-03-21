cmake_minimum_required(VERSION 3.28.1)
project(exchange)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
add_subdirectory(src)

##test
option(BUILD_TESTS "Enable or disable test builds" ON)
if (BUILD_TESTS)
    enable_testing()
    add_subdirectory(test)
    MESSAGE(STATUS "test build enabled")
endif ()