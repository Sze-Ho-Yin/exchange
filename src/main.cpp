#include <iostream>
#include <spdlog/spdlog.h>
#include <boost/asio.hpp>

#include "requests/RequestsConfigurer.h"

using namespace std;

int main() {
    auto threadpools = vector<unique_ptr<boost::asio::thread_pool> >{};
    try {
        threadpools.push_back(requests::start());
    } catch (const exception &e) {
        spdlog::error("OMS start failed. e={}", e.what());
    }
    for (const auto &threadpool: threadpools) {
        threadpool->join();
    }
    return EXIT_SUCCESS;
}
