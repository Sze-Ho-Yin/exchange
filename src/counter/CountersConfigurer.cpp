#include "CountersConfigurer.h"
#include <boost/asio/thread_pool.hpp>
#include <spdlog/spdlog.h>

#include "CounterDispatcher.h"
#include "CounterEngine.h"
#include "processors/PlaceOrderProcessor.h"
#include "processors/Processor.h"

//
// Created by a on 6/4/2025.
//
namespace {
    std::initializer_list<std::shared_ptr<const Processor> > unorderedProcessors = {
        //add processors here
        std::make_shared<const PlaceOrderProcessor>()
    };

    std::once_flag initProcessorFlag;

    std::array<std::shared_ptr<const Processor>, counterEnum::size()> getProcessors() {
        static auto processors = std::array<std::shared_ptr<const Processor>, counterEnum::size()>();
        auto init = []() {
            for (const auto &processor: unorderedProcessors) {
                const int idx = static_cast<int>(processor->type());
                processors[idx] = processor;
            }
        };
        std::call_once(initProcessorFlag, init);
        return processors;
    }
}

namespace counter {
    std::pair<
        std::unique_ptr<boost::asio::thread_pool>,
        std::shared_ptr<const CounterDispatcher> > start() {
        //init engines
        auto threadpool = std::make_unique<boost::asio::thread_pool>(ENGINE_SIZE);
        std::vector<std::unique_ptr<CounterEngine> > engines(ENGINE_SIZE);
        auto processors = std::make_shared<std::array<std::shared_ptr<const Processor>, counterEnum::size()> >(
            getProcessors());
        for (unsigned int i = 0; i < ENGINE_SIZE; ++i) {
            auto engine = std::make_unique<CounterEngine>(i, ENGINE_QUEUE_SIZE, processors);
            engines[i] = std::move(engine);
        }

        //init dispatcher
        auto dispatcher = std::make_shared<const CounterDispatcher>(std::move(engines));

        //start
        dispatcher->start(*threadpool);

        return std::make_pair(std::move(threadpool), std::move(dispatcher));
    }
}
