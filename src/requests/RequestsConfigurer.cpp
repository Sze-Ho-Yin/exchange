#include "RequestsConfigurer.h"

#include <initializer_list>
#include <boost/asio/thread_pool.hpp>

#include "OrderServiceImpl.h"
#include "RequestListener.h"
//
// Created by a on 6/4/2025.
//
namespace {
    std::initializer_list<grpc::Service *> getServices(){
        //add new services here
        static std::initializer_list<grpc::Service *> services{
            new OrderServiceImpl
        };
        return services;
    };
}

namespace requests {
    std::unique_ptr<boost::asio::thread_pool> start() {
        auto threadpool = std::make_unique<boost::asio::thread_pool>(SIZE);
        const auto request_listener = new RequestListener("127.0.0.1", "1234", getServices());
        threadpool->executor().execute(request_listener->start());
        return std::move(threadpool);
    }
}