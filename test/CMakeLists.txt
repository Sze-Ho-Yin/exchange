SET(TEST unitTest)

find_package(GTest)
add_executable(${TEST} main_test.cpp)
target_link_libraries(${TEST} gtest::gtest)