#!/bin/bash

#pip3 install conan
conan profile detect --force
conan profile path default
mkdir ../src/protos/generated