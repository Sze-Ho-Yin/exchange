//
// Created by a on 5/4/2025.
//
#pragma once
#include "../CounterEvent.h"

class Processor {
    virtual void process(const CounterEvent &event) = 0;

    virtual CounterEnum type() = 0;

    virtual ~Processor() = default;
};
