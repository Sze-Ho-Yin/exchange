//
// Created by a on 21/3/2025.
//
#include <grpcpp/server_builder.h>
#include <spdlog/spdlog.h>

#include "OrderServiceImpl.cpp"

using namespace grpc;
using namespace std;

class RequestListener {
private:
    ServerBuilder builder;
    const string address;
    //add required services here
    inline static initializer_list<Service *> services = {
        new OrderServiceImpl
    };

public:
    RequestListener(const string &ip, const string &port): address(ip + ":" + port) {
        builder.AddListeningPort(address, InsecureServerCredentials());
        for (const auto service: services) {
            builder.RegisterService(service);
        }
    }

    ~RequestListener() = default;

    void start() {
        try {
            const unique_ptr server(builder.BuildAndStart());
            spdlog::info("RequestListener start success. listening address={}", address);
            server->Wait();
        } catch (const exception &e) {
            spdlog::error("fail to start requestListener e={}", e.what());
        }
    }
};
