add_subdirectory(protos)

add_executable(${PROJECT_NAME} main.cpp)
add_executable(demo demoClient.cpp)

#internal libraries
target_link_libraries(${PROJECT_NAME} protos)
target_link_libraries(demo protos)

#external libraries
find_package(spdlog)
find_package(Boost)

target_link_libraries(${PROJECT_NAME} spdlog::spdlog)
target_link_libraries(${PROJECT_NAME} boost::boost)

