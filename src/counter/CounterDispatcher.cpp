//
// Created by a on 5/4/2025.
//

#include "CounterDispatcher.h"

#include "CounterConfigurer.h"

CounterDispatcher::CounterDispatcher(std::vector<std::unique_ptr<CounterEngine> > &&engines): engines(std::move(
    engines)) {
}

bool CounterDispatcher::dispatch(std::unique_ptr<CounterEvent> event) const {
    const auto userId = event->getUserId();
    const auto shard = userId % counter::ENGINE_SIZE;
    return engines.at(shard)->offer(std::move(event));
}

void CounterDispatcher::start(boost::asio::thread_pool &threadPool) const {
    for (const auto& engine: engines) {
        threadPool.executor().execute(engine->start());
    };
}
