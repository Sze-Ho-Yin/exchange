
#include "OrderServiceImpl.h"
#include <boost/asio.hpp>


OrderServiceImpl::OrderServiceImpl() = default;

OrderServiceImpl::~OrderServiceImpl() = default;

grpc::ServerUnaryReactor *OrderServiceImpl::placeOrder(grpc::CallbackServerContext *context,
                                                       const PlaceOrderRequest *request,
                                                       PlaceOrderResponse *response) {
    response->set_code(100);
    std::cout << "Not completed" << std::endl;
    auto reactor = context->DefaultReactor();
    auto pool = boost::asio::thread_pool(1);
    pool.executor().execute([reactor]() {
        sleep(5000);
        reactor->Finish(grpc::Status::OK);
    });
    std::cout << "returned" << std::endl;
    return reactor;
}
