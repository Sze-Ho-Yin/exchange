//
// Created by a on 31/3/2025.
//
#pragma once
#include "../counter/CounterDispatcher.h"
#include "service/order_service.grpc.pb.h"


class OrderServiceImpl final : public OrderService::CallbackService {
private:
    std::shared_ptr<const CounterDispatcher> dispatcher;
public:
    explicit OrderServiceImpl(std::shared_ptr<const CounterDispatcher> dispatcher);

    ~OrderServiceImpl() override;

    grpc::ServerUnaryReactor *placeOrder(grpc::CallbackServerContext *context, const PlaceOrderRequest *request,
                                         PlaceOrderResponse *response) override;
};

