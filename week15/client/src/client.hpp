#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <string>

class WorkerClient {
public:
    WorkerClient(const std::string& master_ip, int port);
    void connect_to_master();
    void start_working();

private:
    int sock;
    std::string master_ip;
    int master_port;

    std::string compute_md5(const std::string& input);
    bool increment_password(std::string& password); // Объявление функции
};

#endif // CLIENT_HPP
