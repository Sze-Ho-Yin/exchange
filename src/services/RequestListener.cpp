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
    ServerBuilder _builder;
    const string _address;
    //add required services here
    inline static initializer_list<Service *> services = {
        new OrderServiceImpl
    };

public:
    RequestListener(const string &ip, const string &port): _address(ip + ":" + port) {
        _builder.AddListeningPort(_address, InsecureServerCredentials());
        _builder.AddCompletionQueue();
        for (const auto service: services) {
            _builder.RegisterService(service);
        }
    }

    ~RequestListener() = default;

    auto Start() {
        return [this]() {
            try {
                const unique_ptr server(_builder.BuildAndStart());
                spdlog::info("RequestListener start success. listening _address={}", _address);
                server->Wait();
            } catch (const exception &e) {
                spdlog::error("fail to start requestListener e={}", e.what());
            }
            delete this;
        };
    }
};
