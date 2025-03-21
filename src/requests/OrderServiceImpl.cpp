#include <spdlog/spdlog.h>

#include "service/order_service.grpc.pb.h"

using namespace grpc;

class OrderServiceImpl final : public OrderService::CallbackService {
public:
    OrderServiceImpl() = default;

    ~OrderServiceImpl() override = default;

    ServerUnaryReactor *placeOrder(CallbackServerContext *context, const PlaceOrderRequest *request,
                                   PlaceOrderResponse *response) override {
        response->set_code(100);
        std::cout<<"Not completed"<<std::endl;
        auto reactor = context->DefaultReactor();
        auto pool = boost::asio::thread_pool(1);
        pool.executor().execute([reactor]() {
            sleep(5000);
            reactor->Finish(Status::OK);
        });
        std::cout<<"returned"<<std::endl;
        return reactor;
    }
};
