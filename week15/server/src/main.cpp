#include "server.hpp"
#include <iostream>

int main() {
    try {
        MasterServer server(8080, "098f6bcd4621d373cade4e832627b4f6"); // Example MD5 for "test"
        server.run();
    } catch (const std::exception& e) {
        std::cerr << "Server error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}