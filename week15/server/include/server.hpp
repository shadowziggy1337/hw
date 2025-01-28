#ifndef SERVER_HPP
#define SERVER_HPP

#include <string>
#include <vector>
#include <mutex>
#include <netinet/in.h>

class MasterServer {
public:
    MasterServer(int port, const std::string& target_hash);
    void run();
    
private:
    void handle_client(int client_socket);
    std::string generate_task();
    void stop_server();

    int server_fd;
    sockaddr_in address;
    std::string target_hash;
    std::mutex task_mutex;
    bool password_found = false;
    std::string found_password;
};

std::string compute_md5(const std::string& input);

#endif