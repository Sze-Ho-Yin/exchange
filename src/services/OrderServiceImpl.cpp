#include "service/order_service.grpc.pb.h"

using namespace grpc;

class OrderServiceImpl final : public OrderService::Service {
     Status placeOrder(
          ServerContext* context,
          const PlaceOrderRequest* request,
          PlaceOrderResponse* response) override {
          return Status::OK;
     }
};
