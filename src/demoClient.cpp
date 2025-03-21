//
// Created by a on 21/3/2025.
//
#include "service/order_service.grpc.pb.h"
#include <grpc++/grpc++.h>
#include <memory>
#include <iostream>

using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;

class DemoClient {
public:
    DemoClient(std::shared_ptr<Channel> channel) : _stub{OrderService::NewStub(channel)} {}

    std::string placeOrder(const std::string& request_sample_field) {
        // Prepare request
        PlaceOrderRequest request;

        // Send request
        PlaceOrderResponse response;
        ClientContext context;
        Status status;
        status = _stub->placeOrder(&context, request, &response);

        // Handle response
        if (status.ok()) {
            return "send request success";
        } else {
            std::cerr << status.error_code() << ": " << status.error_message() << std::endl;
            return "RPC failed";
        }
    }

private:
    std::unique_ptr<OrderService::Stub> _stub;
};

int main(int argc, char** argv) {
    std::string server_address{"127.0.0.1:1234"};
    DemoClient client{grpc::CreateChannel(server_address, grpc::InsecureChannelCredentials())};
    std::string request_sample_field{"world"};
    std::string response_sample_field = client.placeOrder(request_sample_field);
    std::cout << "Client received: " << response_sample_field << std::endl;
    return 0;
}