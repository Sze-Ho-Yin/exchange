//
// Created by a on 1/4/2025.
//

#include "CounterEngine.h"
#include <spdlog/spdlog.h>

CounterEngine::CounterEngine(const unsigned int idx, const std::size_t queueSize): idx(idx), counterEvents(queueSize),
    state(std::make_unique<State>()) {
}

CounterEngine::~CounterEngine() = default;

bool CounterEngine::offer(std::unique_ptr<CounterEvent> event) {
    return counterEvents.push(event.release());
}

inline void onEvent(const CounterEvent &event) {
}

std::function<void()> CounterEngine::start() {
    return [this]() {
        while (true) {
            try {
                if (CounterEvent *raw = nullptr; counterEvents.pop(raw)) {
                    std::unique_ptr<CounterEvent> event(raw);
                    onEvent(*event);
                }
            } catch (const std::exception &e) {
                spdlog::error("CounterEngine error. message={}", e.what());
            }
        }
    };
}
