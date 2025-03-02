cmake_minimum_required(VERSION 3.28.1)
project(oms)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(src)
##add_subdirectory(lib)
##target_link_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/lib/src)
##target_link_libraries(${PROJECT_NAME} adder)
#

##test
option(BUILD_TESTS "Enable or disable test builds" ON)
if (BUILD_TESTS)
    enable_testing()
    add_subdirectory(test)
    MESSAGE(STATUS "test build enabled")
endif ()