//
// Created by a on 4/4/2025.
//

#pragma once
#include <google/protobuf/message.h>

#include "CounterEnum.h"

class CounterEvent {
private:
    unsigned long userId;
    grpc::ServerUnaryReactor *const reactor;
    const google::protobuf::Message &request;
    google::protobuf::Message &response;
    const CounterEnum type;

public:
    explicit CounterEvent(
        const unsigned long user_id,
        grpc::ServerUnaryReactor *reactor,
        const google::protobuf::Message &request,
        google::protobuf::Message &response,
        const CounterEnum type)
        : userId(user_id),
          reactor(reactor),
          request(request),
          response(response),
          type(type) {
    }

    //reactor, request, response will be managed by grpc framework
    ~CounterEvent() = default;

    [[nodiscard]] unsigned long getUserId() const {
        return userId;
    }

    [[nodiscard]] grpc::ServerUnaryReactor *getReactor() const {
        return reactor;
    }

    [[nodiscard]] const google::protobuf::Message &getRequest() const {
        return request;
    }

    [[nodiscard]] const google::protobuf::Message &getResponse() const {
        return response;
    }

    [[nodiscard]] CounterEnum getType() const {
        return type;
    }

    explicit operator std::string() const {
        return "CounterEvent(userId=" + std::to_string(userId) + ", type=" + counterEnum::toString(type);
    }
};
