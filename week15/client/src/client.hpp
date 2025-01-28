#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <string>

class WorkerClient {
public:
    WorkerClient(const std::string& master_ip, int port);
    void connect_to_master();
    void start_working();
    
private:
    std::string generate_password(int length);
    void process_task(const std::string& task);
    
    std::string master_ip;
    int master_port;
    int sock = 0;
};

#endif