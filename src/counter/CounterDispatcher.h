//
// Created by a on 5/4/2025.
//
#pragma once
#include <functional>
#include <boost/asio/thread_pool.hpp>

#include "CounterEngine.h"

class CounterDispatcher {
private:
    std::vector<std::unique_ptr<CounterEngine> > engines;

public:
    explicit CounterDispatcher(std::vector<std::unique_ptr<CounterEngine> > &&engines);

    ~CounterDispatcher() = default;

    [[nodiscard]] bool dispatch(std::unique_ptr<CounterEvent> event) const;

    void start(boost::asio::thread_pool &threadPool) const;
};
