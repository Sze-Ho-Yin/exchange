find_package(protobuf CONFIG REQUIRED)
find_package(gRPC CONFIG REQUIRED)

message(STATUS "Using protobuf ${Protobuf_VERSION}")
file(GLOB_RECURSE GENERATED_FILES
        "${CMAKE_CURRENT_SOURCE_DIR}/generated/*.cc"
        "${CMAKE_CURRENT_SOURCE_DIR}/generated/*.h")

add_library(protos ${GENERATED_FILES})
target_link_libraries(protos PUBLIC
        protobuf::libprotobuf
        gRPC::grpc
        gRPC::grpc++)
target_include_directories(protos PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/generated/")
