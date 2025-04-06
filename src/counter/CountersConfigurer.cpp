#include "CountersConfigurer.h"
#include <boost/asio/thread_pool.hpp>

#include "CounterDispatcher.h"
#include "CounterEngine.h"

//
// Created by a on 6/4/2025.
//
namespace counter {
    std::pair<
        std::unique_ptr<boost::asio::thread_pool>,
        std::shared_ptr<const CounterDispatcher> > start() {
        //init engines
        auto threadpool = std::make_unique<boost::asio::thread_pool>(ENGINE_SIZE);
        std::vector<std::unique_ptr<CounterEngine> > engines(ENGINE_SIZE);
        for (unsigned int i = 0; i < ENGINE_SIZE; ++i) {
            auto engine = std::make_unique<CounterEngine>(i, ENGINE_QUEUE_SIZE);
            engines.push_back(std::move(engine));
        }

        //init dispatcher
        auto dispatcher = std::make_shared<const CounterDispatcher>(std::move(engines));

        //start
        dispatcher->start(*threadpool);

        return std::make_pair(std::move(threadpool), std::move(dispatcher));
    }
}
