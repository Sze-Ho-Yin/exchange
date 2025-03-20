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
protoc --cpp_out=./generated ${PROTOS_LOCATION}
protoc --grpc_out=./generated --plugin=protoc-gen-grpc=`which grpc_cpp_plugin` ${PROTOS_LOCATION}
echo -e "${GREEN}generate done, located in $(pwd) ${DEFAULT}"
echo
