#include <iostream>
#include <spdlog/spdlog.h>
#include <boost/asio.hpp>
#include "services/RequestListener.cpp"

using namespace std;

int main() {
    auto threadpool = boost::asio::thread_pool(3);
    try {
        auto initRequestListener = []() {
            RequestListener request_listener("127.0.0.1", "1234");
            request_listener.start();
        };
        threadpool.executor().execute(initRequestListener);
    } catch (const exception &e) {
        spdlog::error("OMS start failed. e={}", e.what());
    }
    threadpool.join();
    return EXIT_SUCCESS;
}
