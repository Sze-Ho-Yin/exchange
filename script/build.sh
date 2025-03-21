#!/bin/sh

ORIGINAL_PATH=$(pwd)
PROTOS_LOCATION=${ORIGINAL_PATH}/../src/protos
SOURCE_LOCATION=${ORIGINAL_PATH}/..


#conan install
cd ${SOURCE_LOCATION}
conan install . --output-folder=build --build=missing -s:b compiler.cppstd=20 -s:h compiler.cppstd=20

#compile proto
cd ${PROTOS_LOCATION}
./build_proto.sh

#cmake and make
cd ${SOURCE_LOCATION}
cmake -S . -DCMAKE_TOOLCHAIN_FILE=conan_toolchain.cmake -DCMAKE_BUILD_TYPE=Release -B ./build
cd ./build
make