#include <iostream>
#include <spdlog/spdlog.h>
#include <boost/asio.hpp>

#include "counter/CountersConfigurer.h"
#include "requests/RequestsConfigurer.h"

using namespace std;

int main() {
    auto threadpools = vector<unique_ptr<boost::asio::thread_pool> >{};
    try {
        auto [counterPool, dispatcher] = counter::start();
        threadpools.push_back(std::move(counterPool));
        threadpools.push_back(requests::start(dispatcher));
    } catch (const exception &e) {
        spdlog::error("OMS start failed. e={}", e.what());
    }
    for (const auto &threadpool: threadpools) {
        threadpool->join();
    }
    return EXIT_SUCCESS;
}
