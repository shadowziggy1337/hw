#include "server.hpp"
#include <iostream>
#include <unistd.h>
#include <thread>
#include <openssl/evp.h>
#include <sstream>
#include <cstring>
#include <iomanip>  
#include <stdexcept> 

MasterServer::MasterServer(int port, const std::string& target_hash) 
    : target_hash(target_hash), password_found(false) { 
    // Создание сокета
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        throw std::runtime_error("Socket creation failed");
    }

    // Настройка параметров сокета
    int opt = 1;
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        close(server_fd);
        throw std::runtime_error("Setsockopt failed");
    }

    // Привязка сокета
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);
    
    if (bind(server_fd, (struct sockaddr*)&address, sizeof(address)) < 0) {
        close(server_fd);
        throw std::runtime_error("Bind failed");
    }
}

void MasterServer::run() {
    // Начало прослушивания
    if (listen(server_fd, 5) < 0) {
        close(server_fd);
        throw std::runtime_error("Listen failed");
    }

    std::cout << "Server started on port " << ntohs(address.sin_port) << std::endl;

    // Основной цикл сервера
    while (!password_found) {
        sockaddr_in client_addr;
        socklen_t client_len = sizeof(client_addr);
        int client_socket = accept(server_fd, (struct sockaddr*)&client_addr, &client_len);
        
        if (client_socket < 0) {
            if (password_found) break; // Выход при условии остановки
            std::cerr << "Accept failed" << std::endl;
            continue;
        }

        // Получение IP-адреса клиента
        char client_ip[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &client_addr.sin_addr, client_ip, sizeof(client_ip));

        // Вывод сообщения о подключении воркера
        std::cout << "Worker connected: " << client_ip << std::endl;

        // Отправка хеша клиенту
        send(client_socket, target_hash.c_str(), target_hash.size(), 0);

        // Создаем ClientInfo с начальным диапазоном
        ClientInfo client_info = {client_socket, 1}; // Начальный диапазон 1

        // Обработка клиента в новом потоке
        std::thread([this, client_info]() mutable {
            this->handle_client(client_info);
            close(client_info.socket);
        }).detach();
    }
    
    stop_server();
}

void MasterServer::handle_client(ClientInfo client_info) {
    try {
        while (!password_found) {
            // Отправка диапазона паролей клиенту
            std::string range_message = std::to_string(client_info.current_range);
            send(client_info.socket, range_message.c_str(), range_message.size(), 0);

            // Получение результата
            char buffer[1024] = {0};
            ssize_t bytes_read = recv(client_info.socket, buffer, sizeof(buffer), 0);
            if (bytes_read <= 0) break;

            std::string result(buffer, bytes_read);
            if (result != "NOTFOUND") {
                std::lock_guard<std::mutex> lock(task_mutex);
                password_found = true;
                found_password = result;
                std::cout << "Password found: " << result << std::endl;
                break;
            }

            // Увеличение диапазона для следующего клиента
            if (client_info.current_range < max_range) {
                client_info.current_range++;
            } else {
                std::cout << "Maximum range reached for this client. Client will be disconnected." << std::endl;
                break;
            }
        }
    } catch (...) {
        std::cerr << "Error handling client" << std::endl;
    }
}

void MasterServer::stop_server() {
    close(server_fd);
    std::cout << "Server stopped" << std::endl;
}

std::string compute_md5(const std::string& input) {
    EVP_MD_CTX* context = EVP_MD_CTX_new();
    unsigned char digest[EVP_MAX_MD_SIZE];
    unsigned int digest_len;

    if (!context) return "";

    EVP_DigestInit_ex(context, EVP_md5(), nullptr);
    EVP_DigestUpdate(context, input.c_str(), input.size());
    EVP_DigestFinal_ex(context, digest, &digest_len);
    EVP_MD_CTX_free(context);

    std::ostringstream oss;
    for (unsigned int i = 0; i < digest_len; i++) {
        oss << std::hex << std::setw(2) << std::setfill('0') << (int)digest[i];
    }
    return oss.str();
}

int main() {
    const int PORT = 8080;
    const std::string TARGET_HASH = "453e41d218e071ccfb2d1c99ce23906a"; // Пример MD5 для "test"

    try {
        MasterServer server(PORT, TARGET_HASH);
        server.run();
    } catch (const std::exception& e) {
        std::cerr << "Server error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
