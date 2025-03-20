add_subdirectory(protos)

add_executable(${PROJECT_NAME} main.cpp)

#internal libraries
target_link_libraries(${PROJECT_NAME} ${SERVICES})
target_link_libraries(${PROJECT_NAME} protos)

#external libraries
find_package(spdlog)
find_package(Boost)
find_package(gRPC)

target_link_libraries(${PROJECT_NAME} spdlog::spdlog)
target_link_libraries(${PROJECT_NAME} boost::boost)
target_link_libraries(${PROJECT_NAME} grpc::grpc)

