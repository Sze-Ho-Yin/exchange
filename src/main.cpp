#include <iostream>
#include <spdlog/spdlog.h>
#include <boost/asio.hpp>

using namespace std;


inline void doSth(int idx) {
    cout << "hello " + to_string(idx) << endl;
}

int main() {
    auto threadpool = boost::asio::thread_pool(1);
    for (int i = 0; i < 2; ++i) {
        auto method = [=] {
            this_thread::sleep_for(chrono::milliseconds(500));
            doSth(i);
        };
        threadpool.executor().execute(method);
    }
    spdlog::info("OMS start success");
    auto method = [] {
        doSth(100);
    };
    threadpool.executor().execute(method);
    threadpool.join();
    return EXIT_SUCCESS;
}
