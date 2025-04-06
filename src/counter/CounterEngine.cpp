//
// Created by a on 1/4/2025.
//

#include "CounterEngine.h"
#include <spdlog/spdlog.h>

CounterEngine::CounterEngine(const unsigned int idx,
                             const std::size_t queueSize,
                             const std::shared_ptr<std::array<std::shared_ptr<const Processor>, counterEnum::size()> >
                             processors): idx(idx),
                                          counterEvents(queueSize),
                                          state(std::make_unique<State>()),
                                          processors(processors) {
}

CounterEngine::~CounterEngine() = default;

bool CounterEngine::offer(std::unique_ptr<CounterEvent> event) {
    return counterEvents.push(event.release());
}

void CounterEngine::onEvent(const CounterEvent &event, const State &state) const {
    try {
        const int index = static_cast<int>(event.getType());
        processors->at(index)->process(event, state);
    } catch (const std::exception &e) {
        spdlog::error("Counter Engine process error. idx={} event={} message={}", idx, static_cast<std::string>(event), e.what());
        event.getReactor()->Finish(grpc::Status::CANCELLED);
    }
}

std::function<void()> CounterEngine::start() {
    return [this]() {
        spdlog::info("Counter Engine idx={} start success", idx);
        while (true) {
            try {
                if (CounterEvent *raw = nullptr; counterEvents.pop(raw)) {
                    std::unique_ptr<CounterEvent> event(raw);
                    onEvent(*event, *state);
                }
            } catch (const std::exception &e) {
                spdlog::error("CounterEngine error. message={}", e.what());
            }
        }
    };
}
