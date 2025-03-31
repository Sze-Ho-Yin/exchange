file(GLOB_RECURSE REQUESTS_FILE
        "${CMAKE_CURRENT_SOURCE_DIR}/*.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

add_library(requests ${REQUESTS_FILE})

#external libraries
find_package(Boost)
find_package(spdlog)

#link external libraries
target_link_libraries(requests boost::boost)
target_link_libraries(requests spdlog::spdlog)

#link internal libraries
target_link_libraries(requests protos)

#include this header
target_include_directories(requests PUBLIC ${REQUESTS_FILE})
