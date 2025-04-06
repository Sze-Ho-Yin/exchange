//
// Created by a on 5/4/2025.
//
#pragma once
#include <boost/asio/thread_pool.hpp>

#include "CounterDispatcher.h"

namespace counter {
    constexpr int ENGINE_SIZE = 8;
    constexpr int ENGINE_QUEUE_SIZE = 1 << 7;

    std::pair<
        std::unique_ptr<boost::asio::thread_pool>,
        std::shared_ptr<const CounterDispatcher> > start();
}
