//
// Created by a on 4/4/2025.
//

#pragma once
#include <google/protobuf/message.h>

#include "../common/CounterEnum.h"

class CounterEvent {
private:
    unsigned int userId;
    grpc::ServerUnaryReactor* const reactor;
    const google::protobuf::Message& request;
    google::protobuf::Message& response;
    const CounterEnum type;

public:
    explicit CounterEvent(
        const unsigned int user_id,
        grpc::ServerUnaryReactor* reactor,
        const google::protobuf::Message& request,
        google::protobuf::Message& response,
        const CounterEnum type)
        : userId(user_id),
          reactor(reactor),
          request(request),
          response(response),
          type(type) {
    }

    //reactor, request, response will be managed by grpc framework
    ~CounterEvent() = default;

    [[nodiscard]] unsigned int getUserId() const {
        return userId;
    }

    [[nodiscard]] grpc::ServerUnaryReactor * getReactor() const {
        return reactor;
    }

    [[nodiscard]] const google::protobuf::Message & getRequest() const {
        return request;
    }

    [[nodiscard]] const google::protobuf::Message & getResponse() const {
        return response;
    }

    [[nodiscard]] CounterEnum getType() const {
        return type;
    }
};
