//
// Created by a on 5/4/2025.
//

#pragma once
#include "Processor.h"

class PlaceOrderProcessor final : public Processor {
public:
    void process(const CounterEvent &event, const State &state) const override {
        spdlog::info("received request userId={}", event.getUserId());
        event.getReactor()->Finish(grpc::Status::OK);
    };

    [[nodiscard]] CounterEnum type() const override {
        return CounterEnum::PLACE_ORDER;
    };

    PlaceOrderProcessor() = default;

    ~PlaceOrderProcessor() override = default;
};
