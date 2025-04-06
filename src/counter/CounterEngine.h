//
// Created by a on 1/4/2025.
//
#pragma once
#include <boost/lockfree/spsc_queue.hpp>
#include <grpcpp/support/server_callback.h>
#include "CounterEvent.h"
#include "State.h"
#include "processors/Processor.h"

class CounterEngine {
private:
    const unsigned int idx;
    boost::lockfree::spsc_queue<CounterEvent *> counterEvents;
    const std::unique_ptr<State> state;
    const std::shared_ptr<std::array<std::shared_ptr<const Processor>, counterEnum::size()> > processors;

public:
    explicit CounterEngine(unsigned int idx,
                           std::size_t queueSize,
                           std::shared_ptr<std::array<std::shared_ptr<const Processor>, counterEnum::size()> > processors);

    ~CounterEngine();

    bool offer(std::unique_ptr<CounterEvent> event);

    std::function<void()> start();
};
