//
// Created by a on 5/4/2025.
//
#pragma once
#include <memory>
#include <boost/asio/thread_pool.hpp>

#include "CounterEngine.h"

namespace counter {
    constexpr int ENGINE_SIZE = 8;
    constexpr int ENGINE_QUEUE_SIZE = 1<<7;

    inline std::unique_ptr<boost::asio::thread_pool> start() {
        auto threadpool = std::make_unique<boost::asio::thread_pool>(ENGINE_SIZE);
        // std::vector<std::unique_ptr<CounterEngine> > engines(ENGINE_SIZE);
        // for (unsigned int i = 0; i < ENGINE_SIZE; ++i) {
        //     auto engine = std::make_unique<CounterEngine>(i, ENGINE_QUEUE_SIZE);
        //     engines.push_back(engine);
        // }
        return std::move(threadpool);

    }
}
