//
// Created by a on 31/3/2025.
//
#pragma once
#include "OrderServiceImpl.h"
#include <grpcpp/server_builder.h>

class RequestListener {
private:
    grpc::ServerBuilder builder;
    const std::string address;

public:
    explicit RequestListener(const std::string &ip, const std::string &port,
                             std::initializer_list<grpc::Service *> services);

    ~RequestListener();

    std::function<void()> start();
};
