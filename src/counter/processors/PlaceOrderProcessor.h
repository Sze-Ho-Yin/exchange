//
// Created by a on 5/4/2025.
//

#pragma once
#include "Processor.h"

class PlaceOrderProcessor final : public Processor {
    void process(const CounterEvent &event) override {
    };

    CounterEnum type() override {
        return CounterEnum::PLACE_ORDER;
    };
};
