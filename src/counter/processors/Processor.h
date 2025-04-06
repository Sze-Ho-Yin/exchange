//
// Created by a on 5/4/2025.
//
#pragma once
#include "../CounterEvent.h"

class Processor {
public:
    Processor() = default;

    virtual void process(const CounterEvent &event, const State &state) const = 0;

    [[nodiscard]] virtual CounterEnum type() const = 0;

    virtual ~Processor() = default;
};
