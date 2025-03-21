#!/bin/bash

BLUE='\033[0;34m'
GREEN='\033[0;32m'
DEFAULT='\033[0m'


PROTOS_LOCATION=$(find . -name "*.proto")

#print the compiled target file
echo -e "${GREEN}start generate proto files"
echo -e "${BLUE}files: ${NC}"
printf "%s\n" $PROTOS_LOCATION

#do compile
~/.conan2/p/b/proto5221ae082c8ea/p/bin/protoc  --cpp_out=./generated ${PROTOS_LOCATION}
~/.conan2/p/b/proto5221ae082c8ea/p/bin/protoc --grpc_out=./generated --plugin=protoc-gen-grpc=/Users/a/.conan2/p/b/grpc8b9d7ae19309d/p/bin/grpc_cpp_plugin ${PROTOS_LOCATION}
echo -e "${GREEN}generate done, located in $(pwd) ${DEFAULT}"
echo
