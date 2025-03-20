#!/bin/bash

#pip3 install conan
conan profile detect --force
conan profile path default

#install grpc and protoc
brew install grpc
brew install protoc