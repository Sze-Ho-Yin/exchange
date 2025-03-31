//
// Created by a on 31/3/2025.
//
#pragma once
#include "OrderServiceImpl.h"
#include <grpcpp/server_builder.h>

class RequestListener {
private:
    grpc::ServerBuilder _builder;
    const std::string _address;
    //add required services here
    inline static std::initializer_list<grpc::Service *> services = {
        new OrderServiceImpl
    };

public:
    RequestListener(const std::string &ip, const std::string &port);

    ~RequestListener();

    std::function<void()> Start();
};
