//
// Created by a on 31/3/2025.
//
#pragma once
#include "service/order_service.grpc.pb.h"


class OrderServiceImpl final : public OrderService::CallbackService {
public:
    OrderServiceImpl();

    ~OrderServiceImpl() override;

    grpc::ServerUnaryReactor *placeOrder(grpc::CallbackServerContext *context, const PlaceOrderRequest *request,
                                         PlaceOrderResponse *response) override;
};

