#include "service/order_service.grpc.pb.h"

using namespace grpc;

class OrderServiceImpl final : public OrderService::Service {
public:
    OrderServiceImpl() = default;

    ~OrderServiceImpl() override = default;

    Status placeOrder(
        ServerContext *context,
        const PlaceOrderRequest *request,
        PlaceOrderResponse *response) override {
        response->set_code(0);
        spdlog::info("received request");
        return Status::OK;
    }
};
