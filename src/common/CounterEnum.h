//
// Created by a on 5/4/2025.
//

#pragma once

enum class CounterEnum {
    PLACE_ORDER,

    //for getting the counter enum size
    COUNTER_ENUM_SIZE
};

namespace counterEnum {
    constexpr int size() {
        constexpr int size = static_cast<int>(CounterEnum::COUNTER_ENUM_SIZE);
        return size;
    }
}
