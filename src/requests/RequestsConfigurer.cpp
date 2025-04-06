#include "RequestsConfigurer.h"

#include <initializer_list>
#include <boost/asio/thread_pool.hpp>

#include "OrderServiceImpl.h"
#include "RequestListener.h"
//
// Created by a on 6/4/2025.
//
namespace {
    std::initializer_list<grpc::Service *> getServices(std::shared_ptr<const CounterDispatcher> dispatcher) {
        //add new services here
        static std::initializer_list<grpc::Service *> services{
            new OrderServiceImpl(dispatcher)
        };
        return services;
    };
}

namespace requests {
    std::unique_ptr<boost::asio::thread_pool> start(std::shared_ptr<const CounterDispatcher> dispatcher) {
        auto threadpool = std::make_unique<boost::asio::thread_pool>(SIZE);
        const auto request_listener = new RequestListener(
            "127.0.0.1",
            "1234",
            getServices(std::move(dispatcher)));
        threadpool->executor().execute(request_listener->start());
        return std::move(threadpool);
    }
}
