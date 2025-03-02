#!/bin/sh

cd ..
conan install . --output-folder=build --build=missing -s:b compiler.cppstd=20 -s:h compiler.cppstd=20
cmake -S . -DCMAKE_TOOLCHAIN_FILE=conan_toolchain.cmake -DCMAKE_BUILD_TYPE=Release -B ./build
cd ./build
make