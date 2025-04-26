file(GLOB_RECURSE REQUESTS_FILE
        "${CMAKE_CURRENT_SOURCE_DIR}/*.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

add_library(counter ${REQUESTS_FILE})

#external libraries
find_package(Boost)
find_package(spdlog)

#link external libraries
target_link_libraries(counter boost::boost)
target_link_libraries(counter spdlog::spdlog)

#link internal libraries
target_link_libraries(counter protos)
target_link_libraries(counter requests)

#include this header
target_include_directories(counter PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/")
