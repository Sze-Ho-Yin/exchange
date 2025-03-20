#!/bin/sh

ORIGINAL_PATH=$(pwd)
PROTOS_LOCATION=${ORIGINAL_PATH}/../src/protos
SOURCE_LOCATION=${ORIGINAL_PATH}/..

##compile proto
#cd ${PROTOS_LOCATION}
#./build_proto.sh

#compile source
cd ${SOURCE_LOCATION}
conan install . --output-folder=build --build=missing -s:b compiler.cppstd=20 -s:h compiler.cppstd=20
cmake -S . -DCMAKE_TOOLCHAIN_FILE=conan_toolchain.cmake -DCMAKE_BUILD_TYPE=Release -B ./build
cd ./build
make