//
// Created by a on 21/3/2025.
//
#include "RequestListener.h"
#include <spdlog/spdlog.h>


RequestListener::RequestListener(const std::string &ip, const std::string &port,
                                 std::initializer_list<grpc::Service *> services): address(ip + ":" + port),
    services(services) {
    builder.AddListeningPort(address, grpc::InsecureServerCredentials());
    for (const auto service: services) {
        builder.RegisterService(service);
    }
}

RequestListener::~RequestListener() = default;

std::function<void()> RequestListener::start() {
    return [this]() {
        try {
            const std::unique_ptr server(builder.BuildAndStart());
            spdlog::info("RequestListener start success. listening address={}", address);
            server->Wait();
        } catch (const std::exception &e) {
            spdlog::error("fail to start requestListener e={}", e.what());
        }
        delete this;
    };
}
