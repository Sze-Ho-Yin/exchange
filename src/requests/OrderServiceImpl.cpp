#include "OrderServiceImpl.h"
#include <boost/asio.hpp>


OrderServiceImpl::OrderServiceImpl(std::shared_ptr<const CounterDispatcher> dispatcher): dispatcher(dispatcher) {
};

OrderServiceImpl::~OrderServiceImpl() = default;

grpc::ServerUnaryReactor *OrderServiceImpl::placeOrder(grpc::CallbackServerContext *context,
                                                       const PlaceOrderRequest *request,
                                                       PlaceOrderResponse *response) {
    auto event = std::make_unique<CounterEvent>(
        request->user_id(),
        context->DefaultReactor(),
        *request,
        *response,
        CounterEnum::PLACE_ORDER);
    return context->DefaultReactor();
}
