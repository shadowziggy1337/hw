#ifndef SERVER_HPP
#define SERVER_HPP

#include <string>
#include <mutex>
#include <atomic>
#include <thread>
#include <vector>
#include <arpa/inet.h>
#include <openssl/evp.h>

struct ClientInfo {
    int socket;
    int current_range; // Текущий диапазон для клиента
};

class MasterServer {
public:
    MasterServer(int port, const std::string& target_hash);
    void run();
    void stop_server();

private:
    void handle_client(ClientInfo client_info);
    
    int server_fd;
    struct sockaddr_in address;
    std::string target_hash;
    std::atomic<bool> password_found;
    std::string found_password;
    std::mutex task_mutex;
    const int max_range = 8; // Максимальный диапазон
};

#endif // SERVER_HPP
