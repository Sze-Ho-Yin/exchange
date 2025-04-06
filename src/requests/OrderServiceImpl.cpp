#include "OrderServiceImpl.h"
#include <boost/asio.hpp>


OrderServiceImpl::OrderServiceImpl(std::shared_ptr<const CounterDispatcher> dispatcher): dispatcher(dispatcher) {
};

OrderServiceImpl::~OrderServiceImpl() = default;

grpc::ServerUnaryReactor *OrderServiceImpl::placeOrder(grpc::CallbackServerContext *context,
                                                       const PlaceOrderRequest *request,
                                                       PlaceOrderResponse *response) {
    auto reactor = context->DefaultReactor();
    auto event = std::make_unique<CounterEvent>(
        request->user_id(),
        reactor,
        *request,
        *response,
        CounterEnum::PLACE_ORDER);
    dispatcher->dispatch(std::move(event));
    return reactor;
}
