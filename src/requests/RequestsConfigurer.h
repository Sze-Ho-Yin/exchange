//
// Created by a on 31/3/2025.
//
#pragma once
#include <memory>
#include <boost/asio/thread_pool.hpp>

namespace requests {
    constexpr int SIZE = 1;
    std::unique_ptr<boost::asio::thread_pool> start();
};
