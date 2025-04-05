//
// Created by a on 31/3/2025.
//
#pragma once
#include <boost/asio.hpp>
#include "RequestListener.h"

namespace requests {
    constexpr int SIZE = 1;

    inline std::initializer_list<grpc::Service *> getServices(){
        //add new services here
        static std::initializer_list<grpc::Service *> services{
            new OrderServiceImpl
        };
        return services;
    };

    inline std::unique_ptr<boost::asio::thread_pool> start() {
        auto threadpool = std::make_unique<boost::asio::thread_pool>(SIZE);
        const auto request_listener = new RequestListener("127.0.0.1", "1234", getServices());
        threadpool->executor().execute(request_listener->start());
        return std::move(threadpool);
    }
};
